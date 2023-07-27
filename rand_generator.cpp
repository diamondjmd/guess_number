#include "rand_generator.h"

int rand_generator::get_random_number(int max_value) {
	std::srand(std::time(nullptr)); // using the current time as seed for random generator
	return std::rand() % max_value;
}

