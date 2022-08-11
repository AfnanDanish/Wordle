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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_SOLUTIONS   2315

char random_solution[6];
int printMenuReturnChoice(void);
bool setup(FILE ** fptDic, FILE ** fptSol);
void readWordFromFile(unsigned int index, char * resWord, FILE * fpt);
void printInstructions(void);
void gamePlay(FILE * fptDict, FILE * fptSol);
void toLowerCase(char * str);

int main()
{
    FILE * fptDictionary = NULL;
    FILE * fptSolutions = NULL;
    setup(&fptDictionary, &fptSolutions);
    int userChoice = 2;

    do
    {
        userChoice = printMenuReturnChoice();

        switch(userChoice)
        {
            case 1:
                gamePlay(fptDictionary, fptSolutions);
                break;
            case 2:
                printInstructions();
                break;
            case 3:
                printf("Exiting the game!\n");
                return(0);
            break;
            default:
                printf("\nEnter a valid choice!\n");
        }
    }
    while(userChoice != 3);
    printf("Exiting the game!\n");
    char testWord[6] = {0};
    for(int i=0; i<100; i++)
    {
        readWordFromFile(i, testWord,fptDictionary);
        printf("The word at index %d is: ", i);
        puts(testWord);
    }


    return 0;
}

void gamePlay(FILE * fptDict, FILE * fptSol)
{
    char solutionWord[6]; //Variable Decleration
    char playerGuess[10];
    int dictionaryIndex;
    char word[6];
    int answer;
    int result;
    int j=0;
    /** Get a random index into the solutions file */
    unsigned int solIdx = rand()% NUM_SOLUTIONS;
    readWordFromFile(solIdx, solutionWord,fptSol);
    //printf("The word at index %d is: ", solIdx);
    //puts(solutionWord);

    /********************* Insert your Code here ********************/
    /** Get input from the player **/
    //puts(solutionWord); Uncomment this to check the code.
    int guesses = 0; //We can count the total guesses with this.
    int duplicate = 0; //We check for duplicate variables with this.
    while(guesses!=6)
    {
        printf("Try %d: ", guesses+1  );
        gets(playerGuess);
        toLowerCase(playerGuess);

        int string_length = strlen(playerGuess);    //To calculate length of string.
        for(dictionaryIndex=0;dictionaryIndex<12947 ;dictionaryIndex++) //Loop checks if the word exists in the dictionary or not.
        {
            readWordFromFile(dictionaryIndex,word,fptDict);
            answer = strcmp(playerGuess,word);
        if(answer == 0) //if the answer is in the dictionary it stops the loop.
        {
            break;
        }
        else    //else it still searches for the word in the dictionary.
        {
            continue;
        }
        }
            if(string_length != 5 || answer!=0) //Condition to check if the word is of 5 letters or the answer exists in dictionary.
            {
                printf("\nERROR!!! WORD NOT FOUND IN DICTIONARY OR LENGTH OF WORD IS NOT 5 LETTERS\n");
                printf("\n");
                continue;
            }
              else
                {for(int i=0;i<5;i++)

                   {
                    if(playerGuess[i] == solutionWord[i])   //If the a letter matches it gives us an asterisk which means it is a correct letter in the correct spot.
                    {
                        printf("*");    //The asterisk means the letter is correct and is in the right spot
                    }

                    else if(playerGuess[i]==solutionWord[0]||playerGuess[i]==solutionWord[2]||playerGuess[i]==solutionWord[3]||playerGuess[i]==solutionWord[4])
                    {   // ^^ condition to check if the letter exists even if it isnt in the right spot. If the letter exists we get a question mark.
                        printf("?");



                    {
                        while(playerGuess[j]!= '\0') //loop checks for all letters
                        {
                            if(playerGuess[i] != playerGuess[j]) //if the letter in the guessed word doesn't exactly match the letter of the
                            {
                             duplicate++;

                            }if(duplicate>1) //if a duplicate is detected then the program puts a dash instead of an excalamation mark.
                            {
                                playerGuess[j]='-';
                            }

                        j++;}
                    }

                }
                    else if(playerGuess[i]!=solutionWord[i]) // if the letter does not exist in the word it gives us a dash.
                    {
                        printf("-");
                    }
                    else
                    {
                        continue; // return to the top of the loop
                    }
                }

              }

                result = strcmp(solutionWord,playerGuess);  //compare the solution to the guess.
                if(result==0)   // if both are equal then we get the message printed.
                {
                    printf("\n");
                    printf("\nYou have entered the correct word");
                    printf("\n");
                    break;
                }
                else
                {
                    printf("\n");
                    guesses++;
                }
                if(guesses>=6) // if the user exhausts all their tries this is printed out.
                {
                    printf("\nYou failed to guess the word");
                    printf("\nThe word was %s",solutionWord);
                    printf("\nBetter luck next time!\n");
                }
            duplicate=0;
    }

}





    /****************************************************************/

    //printf("Player entered the word: ");
    //puts(playerGuess);


bool setup(FILE ** fptDic, FILE ** fptSol)
{
    srand(time(0));
    if((*fptDic = fopen("data\\dictionary.txt", "r")) == NULL)
    {
        printf("Failed to open the dictionary file!\n");
        return (false);
    }

    if((*fptSol = fopen("data\\solutions.txt", "r")) == NULL)
    {
        printf("Failed to open the solutions file!\n");
        return (false);
    }
    return(true);
}

int printMenuReturnChoice(void)
{
    printf("****************************************************************\n");
    printf("Welcome to text based Wordle game.\n\n");
    printf("Enter your choice:\n\n");
    printf("1. New game.\n");
    printf("2. Instructions.\n");
    printf("3. Exit.\n");
    int choice;
    scanf("%d", &choice);
    fflush(stdin);
    printf("\n\n");
    return(choice);
}
void printInstructions(void)
{
    printf("\n");
    printf("*************************************************************************\n");
    printf(" The Wordle game-play requires the player to guess a Five-letter word in\n");
    printf(" six tries. A try is valid if the user enters a 5 letter word that is\n");
    printf(" present in the dictionary. All the letters that are in their\n");
    printf(" correct place (compared to solution) are replaced by a '*' and all the\n");
    printf(" letters that are present in the solution but are out of place are replaced by\n");
    printf(" a '?'. A letter that is absent in the solution is replaced with a hyphen '-'.\n\n");
    printf(" Example word = Zonal (solution) not Case Sensitive.\n");
    printf(" User Try 1:     break\n");
    printf(" program output: ---*-\n");
    printf(" User Try 2:     rolax\n");
    printf(" program output: -*?*-\n");
    printf(" User Try 3:     sonar\n");
    printf(" program output: -***-\n");
    printf(" User Try 4:     zonal\n");
    printf(" program output: *****   Correct! You Win!!\n");

}

void readWordFromFile(unsigned int index, char * resWord, FILE * fpt)
{
    unsigned int offset = (index * 7);
    fseek(fpt, offset, SEEK_SET);
    fgets(resWord, 6, fpt);
}

void toLowerCase(char * str)
{
    int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
        {
			str[i] += 32; //Convert to lowercase
		}
		i += 1;
	}
}
