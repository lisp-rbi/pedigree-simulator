#include<iostream>
#include<sstream>
#include<vector>
#include<ios>
#include<iomanip>
#include <random>
#include "population.h"

std::string pad_with_zeros(int number) {
    std::ostringstream out;
    out << std::internal << std::setfill('0') << std::setw(10) << number;
    return out.str();
}

std::vector<int> generate_normal_random(int mean, int size) {
    const float fmean = static_cast<float>(mean);
    const float sigma = 2.0;
    const int min_offspring = 0;
    const int max_offspring = 6;
    std::vector<int> offsprings;

    std::default_random_engine generator;
    std::normal_distribution<double> distribution(fmean, sigma);

    while (offsprings.size() < size) {
        double number = distribution(generator);
        if ((int(number) >= min_offspring) && (int(number) <= max_offspring)) {
            offsprings.push_back(int(number));
        }
    }
    return offsprings;
}

Population::Population(int x, int y, float z, int k) {
    std::cerr << "Calling class constructor..." << std::endl;
    population_size = x;
    final_population = y;
    male_ratio = z;
    avrg_number_of_offspring = k;
    std::cerr << "population_size = " << population_size << std::endl;
    std::cerr << "final population = " << final_population << std::endl;
    std::cerr << "male_ratio = " << male_ratio << std::endl;
    std::cerr << "avrg_number_of_offspring = " << avrg_number_of_offspring << std::endl;
}

Population::Member Population::makeMember(int id_number, int generation, int sex, std::string motherID) {
    //std::cerr << "Making a new member..." << std::endl;
    Member new_member;
    std::string ID = "ID";
    ID += pad_with_zeros(id_number);
    new_member.ID = ID;
    new_member.generation = generation;
    new_member.sex = sex;
    if (motherID.size() > 0) {
	    new_member.mother = motherID;
    }
    //std::cerr << "Created a new member, ID: " << new_member.ID;
    //std::cerr << ", descends from " << motherID << std::endl;

    return new_member;
}

int Population::initiatePopulation() {
    std::cerr << "Creating initial population, size: " << population_size << std::endl;
    for (int i = 0; i < population_size; i++) {
	    int sex;
        if (i < int(population_size*male_ratio)) {
            sex = 1;
        }
        else {
            sex = 2;
        }
        Member new_member = makeMember(i+1,0,sex,"");
        members.push_back(new_member);
    }
    std::cerr << "Size of created population: " << members.size() << std::endl;
}

void Population::distributeOffspring() {
    std::cerr << "New normal distribution of offspring... " <<  std::endl;
    std::vector<int> offsprings = generate_normal_random(avrg_number_of_offspring,members.size());
    for (int i = 0; i < members.size(); i++) {
        members[i].number_of_offspring = offsprings[i];
    }
}

void Population::breedPopulation() {
    int generation = 1;
    while (members.size() <= final_population) {
        std::cerr << "Adding new generation nr. " << generation << " to the population..." << std::endl;
	    distributeOffspring();
	    std::vector<Member> tmp_members;
        std::cerr << "Creating new members..." << std::endl;
        for (int i = 0; i < members.size(); i++) {
            if (members[i].generation < generation - 1) continue;

	        for (int j = 1; j < members[i].number_of_offspring+1; j++) {
                Member new_member = makeMember(members.size()+tmp_members.size()+1,generation,2,members[i].ID);
                tmp_members.push_back(new_member);
            }
        }
        std::cerr << "Adding new " << tmp_members.size() << " created members to the initial population..." << std::endl;
        for (int i = 0; i < tmp_members.size(); i++) {
	        members.push_back(tmp_members[i]);
            if (members.size() == final_population) break;

        }
        std::cerr << "Now the population has " << members.size() << " members." << std::endl;
        if (members.size() == final_population) break;
	    generation += 1;
    }
}

void Population::printPopulation() {
    std::cerr << "Printing the final population to STDOUT..." << std::endl;
    std::cout << "x,ID,father,mother,YOB,gender," << std::endl;
    for (int i = 0; i < members.size(); i++) {
        std::cout << i+1 << "," << members[i].ID;
        std::cout << "," << members[i].father;
        std::cout << "," << members[i].mother;
        std::cout << "," << 2010 + members[i].generation;
        std::cout << "," << members[i].sex << std::endl;
    }
}

Population::~Population() {
    population_size = 0;
    final_population = 0;
    male_ratio = 0.0;
    members.clear();
    std::cerr << "Class destructor called, population deleted" << std::endl;
}
