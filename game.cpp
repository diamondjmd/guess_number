#include "game.h"

int main(int argc, char** argv) {
    std::string user_name;
    int user_score = 0;
	int user_guess = 0;
	unsigned int level = 0;
    bool game_over = false;
	bool command_show_table = false;
	
	//extern int max_target_value;

	//settings::get_parameters (argc, argv, max_target_value, command_show_table, level);
	settings::get_parameters (argc, argv, command_show_table, level);
	const int target_value = rand_generator::get_random_number(settings::max_target_value);

	// we can combinate -table with -max or -level
    if (command_show_table) {
        score::show(settings::filename);
        if (argc == 2){ 
            return 0; 
        }
    }
  
    std::cout << "Enter your name, please:" << std::endl;
	std::cin >> user_name;

	std::string str_level = (level)?  "level "  + std::to_string(level) + ", ": ""; 
	std::cout << "Enter your guess (" << str_level << "betweend 0 and " << settings::max_target_value << "):\n";

	do {
        std::cin >> user_guess;
        if (std::cin.fail()) {
		    std::cerr << "Bad value!" << std::endl;
		    return -1;
	    }
		user_score++;
	
		if (user_guess < target_value) {
			std::cout << "greater than " << user_guess << std::endl;
		}else if (user_guess > target_value) {
			std::cout << "less than " << user_guess << std::endl;
		}else {
			std::cout << "you won!!\t Your score:" << user_score << std::endl;
			game_over = true;
		}
	

	} while(!game_over);

    //score::save(filename, user_name, user_score);
	score::save_and_overwrite(settings::filename, user_name, user_score);
    score::show(settings::filename);

    return 0;
}