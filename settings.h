#pragma once

#include <iostream>
#include <string>


namespace settings {

    const std::string filename = "high_scores.txt";
    extern int max_target_value;
//int settings::max_target_value = 100;

    //set all status variables according to parameters from command line
    //void get_parameters (int argc, char **argv, int &max_target_value, bool &command_show_table, unsigned int &level);
    void get_parameters (int argc, char **argv, bool &command_show_table, unsigned int &level);
} // namespace settings
