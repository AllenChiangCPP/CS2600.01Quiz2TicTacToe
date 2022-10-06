#include <stdio.h>
//#include <stdlib.h>
//Tic Tac Toe game between 2 players or player vs computer

int playerVsPlayer() //player vs player game, prints who is the winner 
{
    //encase in while loop for game duration, ends if there is a winner or draw

    //prints game board and current players turn, game board has numbers to indicate which spaces available, will be filled out with an X for player 1 or and O for player 2
        //0|1|2
        //3|4|5
        //6|7|8
    
    //asks player 1 for input and checks validity

    //asks player 2 for input and checks validity 

    //runs win checker to see if there is a winner or draw

    return 0;
}
int playerVsComputer() //player vs computer game, prints who is the winner, computer picks random numbers
{
    //encase in while loop for game duration, ends if there is a winner or draw

    //prints game board and current players turn, game board has numbers to indicate which spaces available, will be filled out with an X for player 1 or and O for computer
        //0|1|2
        //3|4|5
        //6|7|8

    //asks player 1 for input and checks validity

    //computer randomly generates a number, if number is invalid regenerates a number
        //or make computer generate from a list of 0-8, with a number in the list being taken away if player 1 has already picked the space

    //runs win checker to see if there is a winner or draw


    return 0;
}
int winChecker(int givenBoard[8]) //function that checks if there is a winner based on inputted array
{
    //switch statements
        //row: 0 = 1 = 2, 3 = 4 = 5, 6 = 7 = 8
        //column: 0 = 3 = 6, 1 = 4 = 6. 6 = 7 = 8
        //diagonal: 0 = 4 = 8, 2 = 4 = 6
        //if given int array is full and no winner, declare a draw
    return 0;
}

int main()
{
    int userPlayAgain = 1;
    while (userPlayAgain == 1)
    {
        int userGamePick;
        int userInputPlayAgain;
        //int pickGameStatus = 1; //int for while loop, if while loop is 1
        //create an empty board, an int array with a size of 8 to represent the grid, player 1 is represented as 1 in the code while player 2 is represented as 2
        //  0,1,2
        //  3,4,5
        //  6,7,8
        int gameBoard[8];
        printf("WELCOME TO TIC TAC TOE!\n");
        //if 1 is chosen, break out of loop, starts player v player game as playerVsPlayer() function
        //if 2 is chosen, break out of loop, start player vs computer game as playerVsComputer() function
        //else, print invalid input and ask for input again
        //prompt user for game they wish to play, encase in loop, break if user inputs a valid unput
        //read information from console, 1 = player vs player, 2 = player vs computer, anything else = invalid input
        while (1)
        {
            int userGameInput;
            printf("1: Person vs. Person\n");
            printf("2: Person vs. Computer\n");
            printf("Enter your choice (1 or 2): \n");
            scanf("%d", &userGameInput);
            if (userGameInput == 1 || userGameInput == 2)
            {
                userGamePick = userGameInput;
                break;
            }
            printf("INVALID RESPONSE\n");
            getchar();
            //pickGameStatus = 1;
        }
        printf("You have entered choice %d\n", userGamePick);
        if (userGamePick == 1)
        {
            playerVsPlayer();
        }
        if (userGamePick == 2)
        {
            playerVsComputer();
        }
        //ask the user if they want to play again, 1 == yes, 2 == no
        //if user inputs 1, loop continues, if user inputs 2, exit loop, if neither 1 or 2, print invalid input 
        while (1)
        {
            printf("Would you like to play again? \n");
            printf("1: Yes \n");
            printf("2: No \n");
            scanf("%d", &userInputPlayAgain);
            if (userInputPlayAgain == 1)
            {
                break;
            }
            if (userInputPlayAgain == 2)
            {
                printf("Goodbye. \n");
                userPlayAgain = 2;
                break;
            }
            printf("INVALID RESPONSE\n");
            getchar();
        }
        
        
    }
    
   



    
    return 0;

}