# pedigree-simulator
A program to create a synthetic pedigree

Compiling the program:

g++ pedigreesim.cpp population.cpp -o pedigreesim

Execution:

./pedigreesim initial_population final_population male_ratio average_offspring > output.csv

Input parameters:

initial_population (int): Size of the founder population. For 1 it creates a tree, for >1 it creates a forest
final_population (int): Size of the final population. The program stops upon reaching the desired population size without finishing the initiated generation.
male_ratio (float): Fraction of the initial population that is male. At this point please keep this number at 0.0, as we currently only follow the maternal lines.
average_offspring (int): Average number of offspring that an individual has in a given generation.

The program starts with an initial population of the desired size and at each generation it creates new members. Each member has an assigned ID, maternal and paternal IDs (for now paternal IDs are empty), which generation it belongs to, sex and number of offspring. At the beginning of a new generation, the program randomly assigns a new number of offspring to each existing member according to the normal distribution with mean = average_offspring and sigma = 1.0 or 2.0. Number of offspring for each member can be between and including 0 and 6, so please choose average_offspring whithin that range. 
Thereafter the program adds new members to the population accordingly. Each member can generate offspring in 2 consecutive subsequent generations, afterwards it stops. The execution ends when final_population is reached.
 
The program throws the final pedigree in CSV format to the STDOUT which can be redirected to a file. YOB for each individual is given as 2010 (chosen arbitrarily) + the generation the individual belongs to. Comments during the execution are directed to STDERR.
