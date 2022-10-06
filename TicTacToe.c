#include<stdio.h>
//Tic Tac Toe game between 2 players or player vs computer

int playerVsPlayer() //player vs player game, prints who is the winner and who is the lower
{
    //encase in while loop for game duration, prints who is the winner and who is the user
    return 0;
}
int playerVsComputer()
{
    return 0;
}
int winChecker(char givenBoard[8]) //function that checks if there is a winner based on inputted array
{
    return 0;
}

int main()
{
    while (1)
    {
        int userGamePick;
        //int pickGameStatus = 1; //int for while loop, if while loop is 1
        //create an empty board, a character array with a size of 8 to represent the grid
        //  0,1,2
        //  3,4,5
        //  6,7,8
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
    }
    
   



    
    return 0;

}