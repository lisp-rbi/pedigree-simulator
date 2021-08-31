#include<iostream>
#include<vector>
#include "population.h"

using namespace std;

int main(int argc, char *argv[]) {

    int size = atoi(argv[1]);
    int final_population = atoi(argv[2]);
    float male_ratio = atof(argv[3]);
    int ano = atoi(argv[4]);
    Population newpop(size,final_population,male_ratio,ano);
    newpop.initiatePopulation();
    newpop.breedPopulation();
    newpop.printPopulation();

    return 0;
}
