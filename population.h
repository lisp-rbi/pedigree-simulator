#include<vector>
#include<string>

class Population {

    private:
        int population_size;
        int final_population;
        float male_ratio;
        int avrg_number_of_partners;
        int avrg_number_of_offspring;

    public:
        Population(int x, int y, float z, int w, int q);

        struct Member {
            std::string ID;
            int generation;
            int sex;
            int number_of_partners;
            int number_of_offspring;
            std::string father;
            std::string mother;
        };

        std::vector<Member> males;
        std::vector<Member> females;
        Member makeMember(int id_number, int generation, int sex, std::string fatherID, std::string motherID);
        int initiatePopulation();
        void distributeOffspring();
        void distributePartners();
        int breedPopulation();
	    void printPopulation();
        ~Population();
};