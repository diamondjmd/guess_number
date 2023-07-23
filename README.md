# Guess the number

## Description
 A simple guess the number type game mini-project, with a high score table. The computer thinks a random number, the user tries to guess. At the same time, the number of attempts is counted and a table of records is formed. 

 * If the user has entered a number less than the specified one, the hint **_less than_** is displayed. 
 * If the user has entered a number greater than the given one, the hint **_greater than_** is displayed. 
 * If the user finally guesses the number, the message **_you win!_** is displayed

 ## Output example
 ```
 > guess_the_number
    Hi! Enter your name, please:
    username
    Enter your guess:
    42
    less than 42
    1
    greater than 1
    33
    you win! attempts = 3
    High score table:
    username 13
    SomeOtherName 24
    username 9
    username 3
   ```