#include<vector>
#include<string>

class Population {

    private:
        int population_size;
        int final_population;
        float male_ratio;
        int avrg_number_of_offspring;

    public:
        Population(int x, int y, float z, int k);
        
        struct Member {
            std::string ID;
            int generation;
            int sex;
            int number_of_offspring;
            std::string father;
            std::string mother;
        };

        std::vector<Member> members;
	Member makeMember(int id_number, int generation, int sex, std::string motherID);
        int initiatePopulation();
        void distributeOffspring();
        void breedPopulation();
	void printPopulation();
        ~Population();
};
