#include <iostream>
#include <fstream>
#include <map>
#include <string>


namespace score {
    
    //naive save_score function which save in a text file the user score, 
    //returns true if the file was successfully saved, otherwise returns false
    bool save(const std::string &filename, const std::string &username, const int user_score);

    // save score function adapted to Game Behavior 5 (See readme)
    //returns true if the file was successfully saved, otherwise returns false
    bool save_and_overwrite(const std::string &filename, const std::string &username, const int user_score);

    //show scores saved in a text file, returns true if the file was successfully read, otherwise returns false
    bool show(const std::string &filename);
} // namespace score 