#include "settings.h"

int settings::max_target_value = 100;

void settings::get_parameters (int argc, char **argv, bool &command_show_table, unsigned int &level){
    if ( argc > 4) {
        std::cerr << "Too many arguments" << std::endl;
        exit(-1);
    }

    std::string parameter;
    
    bool unknown_command;
    for (int i = 1;  i < argc; i++){
        bool unknown_command = true;
        parameter = argv[i];

        if (parameter == "-max"){
            i++; 
            if (argc < 3 || i >= argc || !(settings::max_target_value = atoi(argv[i]))) {
                std::cerr << "wrong value, -max expect an integer value" << std::endl;
                exit(-1); 
            }
            unknown_command = false;
        }

        if (parameter == "-table"){
            command_show_table = true;
            unknown_command = false;
        }

        if (parameter == "-level"){
            i++; 
            if( argc < 3 || i >= argc || !(level = atoi(argv[i]))){
                std::cerr << "wrong value, -level expect an integer value" << std::endl;
                 exit(-1); 
            }

            // hardcoded level (see readme, section command -level)
            switch (level) {
                case 1: settings::max_target_value = 9;  break;
                case 2: settings::max_target_value = 49; break;
                case 3: settings::max_target_value = 99; break;
                default:
                    std::cerr << "The level " << level << " is not implemented yet\n"; 
                    exit (-1);
                break;
            }
             unknown_command = false;
        }

        if (unknown_command){
             std::cerr << "command '" << parameter << "' not found \n";
              exit (-1);
        }
    }
}