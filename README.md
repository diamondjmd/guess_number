# Guess the number

## Description
 A simple mini-project at the more basic C++ knowledge level. **Guess the number** is a simple game, which saves the all attempts of player in a text file. The game's goal is to guess a number and keep the high records
 ### Game behavior

 1. If the user has entered a number less than the specified one, the hint **_less than_** is displayed. 
 2. If the user has entered a number greater than the given one, the hint **_greater than_** is displayed. 
 3. If the user finally guesses the number, the message **_you won!_** is displayed
 4. When reading the table of attempts (scores) for each player, determine the minimum value of the number attempts and output  only them. Example, the contents of the high score table:
   ```
      A 15
      B 12
      A 10
      B 1
      A 3
   ```
   The Players A and B, have 3 and 2 entries, respectively. But at the end of the application, the game display only the minimum values (these are still records):
   ```
      High score table:
      A 3
      B 1
   ```


 5. When saving the table of attempts (scores), the game overwrite the previous result of the player if the current result has become better. Example:
   ```
      B 13
      A 12
      C 5
   ```
   Then, suppose that the player A has won the game again in 5 attempts. The contents of the
   high score table should change as follows:
   ```
      B 13
      C 5
      A 5
   ```

 ## Game output example
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

   ## Commands 
   ### -max
   Command line parameter with one numeric argument, with which you can set the maximum value for the hidden number.
   #### Command example:
   ```
      $ ./guess_number -max 42
   ```
   ### -table
   Command line parameter with no arguments, with which you can display the high score table immediately, without the need to start the game. 
   #### Command example:
   ```
      $ ./guess_number -table
   ```
   ### -level
   Command line parameter with one numeric argument, through which you can set the level of difficulty. The maximum value of the hidden number depends on the difficulty level. For example, let's add 3 difficulty levels:
   1. The maximum value is 10 (a guessing range  range from 0 to 9)
   2. The maximum value is 50 (a guessing range from 0 to 49)
   3. The maximum value is 100 (a guessing range  from 0 to 99)

   #### Command example:
   ```
   $ ./guess_number -level 3
   ```


