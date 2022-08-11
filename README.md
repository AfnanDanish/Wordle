# Wordle
Wordle Game created in C
/****************************************************************************************
*   The program presents a menu to the user/player to start the game. The
*   game-play requires the player to guess a 5-letter word in 6 tries. A try is valid if
*   the user enters a 5 letter word that is present in the dictionary. After the user has
*   entered a valid word, it needs to be compared against the solution. All the letters
*   that are in their correct place (compared to solution) are replaced by a '*' and all
*   the letters that are present in the solution but are out of place are replaced by a
*   '?'. A letter that is not present in the solution is replaced with a hyphen '-'.
*
*   Example word = Zonal (solution) not Case Sensitive
*   User Try 1:     break
*   program output: ---*-
*   User Try 2:     rolax
*   program output: -*?*-
*   User Try 3:     sonar
*   program output: -***-
*   User Try 4:     zonal
*   program output: *****   Correct! You Win!!
*
*
*/
