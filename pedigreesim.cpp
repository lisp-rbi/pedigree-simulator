#include<iostream>
#include<assert.h>
#include "population.h"

int main(int argc, char *argv[]) {

    int rc = 0;
    int size = atoi(argv[1]);
    int final_population = atoi(argv[2]);
    float male_ratio = atof(argv[3]);
    int anp = atoi(argv[4]);
    int ano = atoi(argv[5]);
    assert(size < final_population);
    assert(male_ratio < 1.0);
    assert(ano >= 0 && ano < 7);
    assert(anp >= 0 && anp < 6);
    Population newpop(size,final_population,male_ratio,anp,ano);
    rc = newpop.initiatePopulation();
    rc = newpop.breedPopulation();
    newpop.printPopulation();

    return rc;
}
