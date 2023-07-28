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

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(guess_number PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(guess_number PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()