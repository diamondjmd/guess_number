cmake_minimum_required(VERSION 3.5)

project(project_guess_number)

add_executable(guess_number 
    game
    game.cpp
    score
    score.cpp
    settings
    settings.cpp
    rand_generator
    rand_generator.cpp

)

set_target_properties(guess_number PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)