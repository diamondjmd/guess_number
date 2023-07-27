
#include "score.h"

bool score::save_and_overwrite(const std::string &filename, const std::string &username, const int user_score){
    std::ifstream file{filename};

    if (!file.is_open()) {
        std::cout << "Cannot open the file '" << filename << "'\n";

        // create a new file if high score file doesn't exist
        if (!filename.empty()){ 
            std::cout << "Creating a new file..!\n";
            std::ofstream new_file {filename, std::ios_base::app};
            new_file << username << ' ' << user_score << std::endl;
            new_file.close();
            return true;
        }else{
            return false;
        }
    }

    std::string temp_filename = "temp_high_scores.txt";
    std::ofstream temp_file{temp_filename, std::ios_base::app};
    std::string curr_username;
    int score = 0;

    while (file >> curr_username) {
        file >>score;
        if (!(username == curr_username  &&  user_score < score )){
             temp_file << curr_username<< ' ' <<score << std::endl;
        }
    }
    file.close();

    temp_file << username << ' ' << user_score << std::endl;
    temp_file.close();

    std::remove(filename.c_str());
    std::rename(temp_filename.c_str(), filename.c_str());


    return true;
}

bool score::save(const std::string &filename, const std::string &username, const int user_score){
    std::ofstream file{filename, std::ios_base::app}; //opening the file in the append mode 
    if (!file.is_open()) {
        std::cerr << "Failed to open file '" << filename << "' for write!\n";
        return false;
    }
    file << username << ' ' << user_score  << std::endl; // Append new results to the file:
    file.close(); // I could be skip this line, but I prefer always close the file

    return true;
}

bool score::show(const std::string &filename){
    std::ifstream file{filename};
    std::map<std::string, int> high_scores; //dictionary with high scores 

    if (!file.is_open()) {
        std::cerr << "Failed to open file '" << filename << "' for read!\n";
        return false;
    }

    std::cout << "\n***** High scores table ****\n";

    std::string username;
    int score = 0;
    
    while (file >> username) {
        file >> score;
        if ((!high_scores.count(username)) || (score < high_scores[username])){
            high_scores[username] = score;   
        }
        //std::cout << username << '\t' << score << std::endl;
    }
    file.close(); // I could be skip this line, but I prefer always close the file

    for (auto element : high_scores) {
        std::cout <<"\t"<< element.first << "\t" << element.second << std::endl;
    }
    std::cout << " ****************************\n";

    return true;
}
