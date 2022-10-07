#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Tic Tac Toe game between 2 players or player vs computer

//modify win checker by changing it to take in and check a 2d array 
    //givenBoard[1] -> givenBoard[0][0], givenBoard[2] -> givenBoard[0][1], etc
int winChecker(char givenBoard[9]) //function that checks if there is a winner based on inputted array
{
    //0 1 2
    //3 4 5
    //6 7 8
    //if else statements:
        //row: 0 = 1 = 2, 3 = 4 = 5, 6 = 7 = 8
        //column: 0 = 3 = 6, 1 = 4 = 7, 2 = 5 = 8
        //diagonal: 0 = 4 = 8, 2 = 4 = 6
            //after checking either row, column, or diagonal all equal, checks if symbol is X or O to determine which player wins
        //if given int array is full and no winner, declare a draw
        //return 1 for player 1 win, 2 for player 2 win, 3 for draw, 0 by default
    //ROW CHECKS
    if(givenBoard[0] == givenBoard[1] && givenBoard[1] == givenBoard[2]) 
    {
        if(givenBoard[0] == 'X')
        {
            return 1;
        }
        if(givenBoard[0] == 'O')
        {
            return 2;
        }
    }
    else if(givenBoard[3] == givenBoard[4] && givenBoard[4] == givenBoard[5]) 
    {
        if(givenBoard[3] == 'X')
        {
            return 1;
        }
        if(givenBoard[3] == 'O')
        {
            return 2;
        }
    }
    else if(givenBoard[6] == givenBoard[7] && givenBoard[7] == givenBoard[8]) 
    {
        if(givenBoard[6] == 'X')
        {
            return 1;
        }
        if(givenBoard[6] == 'O')
        {
            return 2;
        }
    }
    //COLUMN CHECKS
    else if(givenBoard[0] == givenBoard[3] && givenBoard[3] == givenBoard[6]) 
    {
        if(givenBoard[0] == 'X')
        {
            return 1;
        }
        if(givenBoard[0] == 'O')
        {
            return 2;
        }
    }
    else if(givenBoard[1] == givenBoard[4] && givenBoard[4] == givenBoard[7]) 
    {
        if(givenBoard[1] == 'X')
        {
            return 1;
        }
        if(givenBoard[1] == 'O')
        {
            return 2;
        }
    }
    else if(givenBoard[2] == givenBoard[5] && givenBoard[5] == givenBoard[8]) 
    {
        if(givenBoard[2] == 'X')
        {
            return 1;
        }
        if(givenBoard[2] == 'O')
        {
            return 2;
        }
    }
    //DIAGONAL
    else if(givenBoard[0] == givenBoard[4] && givenBoard[4] == givenBoard[8]) 
    {
        if(givenBoard[0] == 'X')
        {
            return 1;
        }
        if(givenBoard[0] == 'O')
        {
            return 2;
        }
    }
    else if(givenBoard[2] == givenBoard[4] && givenBoard[4] == givenBoard[6]) 
    {
        if(givenBoard[2] == 'X')
        {
            return 1;
        }
        if(givenBoard[2] == 'O')
        {
            return 2;
        }
    }
    //FULL BOARD
    else if(givenBoard[0] != '1'&& givenBoard[1] != '2'&& givenBoard[2] != '3'&& givenBoard[3] != '4' &&
    givenBoard[4] != '5'&& givenBoard[5] != '6'&& givenBoard[6] != '7' && givenBoard[7] != '8' && givenBoard[8] != '9')
    {
        return 3;
    }
    return 0;
}

//modify board printer to take in a 2d array instead of a regular array
    //givenBoard[1] -> givenBoard[0][0], givenBoard[2] -> givenBoard[0][1], etc
void boardPrinter(char givenBoard[9]) //fuction that takes a char array and prints the board
{
    printf("+-----------+\n");
    printf("| %c | %c | %c | \n",givenBoard[0], givenBoard[1], givenBoard[2]);
    printf("+-----------+\n");
    printf("| %c | %c | %c | \n",givenBoard[3], givenBoard[4], givenBoard[5]);
    printf("+-----------+\n");
    printf("| %c | %c | %c | \n",givenBoard[6], givenBoard[7], givenBoard[8]);
    printf("+-----------+\n");
}

//modify to work with a 2d array, take 2 user inputs from same scanf line to represent row and column
int playerVsPlayer() //player vs player game, prints who is the winner 
{
    char gameBoard[9] = {'1','2','3','4','5','6','7','8','9'}; 
    //make a blank 2d array to represent the gameboard
    //char gameBoard[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}; 
    while(1)
    {
        //create an empty board, an char array with a size of 8 to represent the grid, player 1 is represented as X while player 2 is represented as O
        //  1,2,3
        //  4,5,6
        //  7,8,9
        //char array will be filled with number 0 - 8 to represent available spaces on the board and be replaced by Xs or Os by the players or computers
        
        //printf("You have entered choice 1, player vs player.\n");
        //print empty gameboard as test

        //encase in while loop for game duration, ends if there is a winner or draw
        
        //asks player 1 for input and checks validity
        boardPrinter(gameBoard);
        while (1)
        {
            int player1Input = 10;
            printf("Player 1 Turn: \n");
            scanf("%d", &player1Input);
            if (gameBoard[player1Input-1] != 'X' && gameBoard[player1Input-1] != 'O' && player1Input > 0 && player1Input < 10)
            {
                gameBoard[player1Input-1] = 'X';
                break;
            }
            printf("INVALID RESPONSE\n");
            getchar();
        }
        if(winChecker(gameBoard) == 1)
        {
            printf("Player 1 wins!\n");
            break;
        }
        else if(winChecker(gameBoard) == 2)
        {
            printf("Player 2 wins!\n");
            break;
        }
        else if(winChecker(gameBoard) == 3)
        {
            printf("Draw!\n");
            break;
        }
        //runs win checker to see if there is a winner or draw

        //asks player 2 for input and checks validity 
        boardPrinter(gameBoard);
        while (1)
        {
            int player2Input = 10;
            printf("Player 2 Turn: \n");
            scanf("%d", &player2Input);
            if (gameBoard[player2Input-1] != 'X' && gameBoard[player2Input-1] != 'O' && player2Input > 0 && player2Input < 10)
            {
                gameBoard[player2Input-1] = 'O';
                break;
            }
            printf("INVALID RESPONSE\n");
            getchar();
        }
        if(winChecker(gameBoard) == 1)
        {
            printf("Player 1 wins!\n");
            break;
        }
        else if(winChecker(gameBoard) == 2)
        {
            printf("Player 2 wins!\n");
            break;
        }
        else if(winChecker(gameBoard) == 3)
        {
            printf("Draw!\n");
            break;
        }
    }
    return 0;
}

//modify to work with a 2d array, take 2 user inputs from same scanf line to represent row and column
//modify so 2 random number generators to generate a random row and random column for the computer
int playerVsComputer() //player vs computer game, prints who is the winner, computer picks random numbers
{
    //copy most of the code from player vs player, modify player 2 section 
    //encase in while loop for game duration, ends if there is a winner or draw
    char gameBoard[9] = {'1','2','3','4','5','6','7','8','9'}; 
    while(1)
    {
        //prints game board and current players turn, game board has numbers to indicate which spaces available, will be filled out with an X for player 1 or and O for computer
        //0|1|2
        //3|4|5
        //6|7|8

    //asks player 1 for input and checks validity
        boardPrinter(gameBoard);
        while (1)
        {
            int player1Input = 10;
            printf("Player 1 Turn: \n");
            scanf("%d", &player1Input);
            if (gameBoard[player1Input-1] != 'X' && gameBoard[player1Input-1] != 'O' && player1Input > 0 && player1Input < 10)
            {
                gameBoard[player1Input-1] = 'X';
                break;
            }
            printf("INVALID RESPONSE\n");
            getchar();
        }
        //runs win checker to see if there is a winner or draw
        if(winChecker(gameBoard) == 1)
        {
            printf("Player 1 wins!\n");
            break;
        }
        else if(winChecker(gameBoard) == 2)
        {
            printf("Computer wins!\n");
            break;
        }
        else if(winChecker(gameBoard) == 3)
        {
            printf("Draw!\n");
            break;
        }
        
    //computer randomly generates a number, if number is invalid regenerates a number
        //or make computer generate from a list of 0-8, with a number in the list being taken away if player 1 has already picked the space
    
    printf("Computer Turn: \n");
        while (1)
        {
            srand(time(NULL));
            int computerInput = rand() % 9; 
            //scanf("%d", &player2Input);
            if (gameBoard[computerInput] != 'X' && gameBoard[computerInput] != 'O' && computerInput >= 0 && computerInput < 9)
            {
                printf("%d\n", computerInput+1);
                gameBoard[computerInput] = 'O';
                break;
            }
            //getchar();
        }
        if(winChecker(gameBoard) == 1)
        {
            printf("Player 1 wins!\n");
            break;
        }
        else if(winChecker(gameBoard) == 2)
        {
            printf("Computer wins!\n");
            break;
        }
        else if(winChecker(gameBoard) == 3)
        {
            printf("Draw!\n");
            break;
        }
    //runs win checker to see if there is a winner or draw
    }
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
        //printf("You have entered choice %d\n", userGamePick);
        if (userGamePick == 1)
        {
            printf("You have entered choice 1, player vs player.\n");
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