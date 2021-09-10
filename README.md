# pedigree-simulator
A program to create a synthetic pedigree

Compiling the program:

g++ pedigreesim.cpp population.cpp -o pedigreesim

Execution:

./pedigreesim initial_population final_population male_ratio average_partners average_offspring > output.csv

Input parameters:

initial_population (int): Size of the founder population. Lowest viable number is shown to be 4.

final_population (int): Size of the final population. The program stops upon reaching the desired population size without finishing the initiated generation.

male_ratio (float): Fraction of the population that is male. Probably keep this number around 0.5, but you can experiment.

average_partners (int): Average number of partners that males have in a given generation.

average_offspring (int): Average number of offspring that females have in a given generation.

The program starts with an initial population of the desired size and composition and at each generation it creates new members. Each member has an assigned ID, maternal and paternal IDs, which generation it belongs to, sex, number of partners (males) and number of offspring(females). At the beginning of a new generation, the program randomly assigns a new number of partners to each existing male and a number of offspring to each existing female according to the normal distribution with mean = average_partners/average_offspring and sigma = 2.0. Number of partners/offspring for each member can be between and including 0 and 6, so please choose average_partners average_offspring whithin that range. 
Thereafter the program adds new members to the population accordingly. Each female can generate offspring in 2 consecutive subsequent generations, afterwards it stops. For males there is no such constraint. The execution ends when final_population is reached.
 
The program throws the final pedigree in CSV format to the STDOUT which can be redirected to a file. YOB for each individual is given as 2000 (chosen arbitrarily) + the generation the individual belongs to. Comments during the execution are directed to STDERR.
