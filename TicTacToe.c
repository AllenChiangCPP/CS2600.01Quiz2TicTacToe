#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Tic Tac Toe game between 2 players or player vs computer

//modify win checker by changing it to take in and check a 2d array 
    //givenBoard[1] -> givenBoard[0][0], givenBoard[2] -> givenBoard[0][1], etc
int winChecker(char givenBoard[3][3]) //function that checks if there is a winner based on inputted array
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
    if(givenBoard[0][0] == givenBoard[0][1] && givenBoard[0][1] == givenBoard[0][2]) 
    {
        if(givenBoard[0][0] == 'X')
        {
            return 1;
        }
        else if(givenBoard[0][0] == 'O')
        {
            return 2;
        }
    }
    else if(givenBoard[1][0] == givenBoard[1][1] && givenBoard[1][1] == givenBoard[1][2])
    {
        if(givenBoard[1][0] == 'X')
        {
            return 1;
        }
        else if(givenBoard[1][0] == 'O')
        {
            return 2;
        }
    }
    else if(givenBoard[2][0] == givenBoard[2][1] && givenBoard[2][1] == givenBoard[2][2])
    {
        if(givenBoard[2][0] == 'X')
        {
            return 1;
        }
        else if(givenBoard[2][0] == 'O')
        {
            return 2;
        }
    }
    //COLUMN CHECKS
    else if(givenBoard[0][0] == givenBoard[1][0] && givenBoard[1][0] == givenBoard[2][0])
    {
        if(givenBoard[0][0] == 'X')
        {
            return 1;
        }
        else if(givenBoard[0][0] == 'O')
        {
            return 2;
        }
    }
    else if(givenBoard[0][1] == givenBoard[1][1] && givenBoard[1][1] == givenBoard[2][1]) 
    {
        if(givenBoard[0][1] == 'X')
        {
            return 1;
        }
        else if(givenBoard[0][1] == 'O')
        {
            return 2;
        }
    }
    else if(givenBoard[0][2] == givenBoard[1][2] && givenBoard[1][2] == givenBoard[2][2])
    {
        if(givenBoard[0][2] == 'X')
        {
            return 1;
        }
        else if(givenBoard[0][2] == 'O')
        {
            return 2;
        }
    }
    //DIAGONAL
    else if(givenBoard[0][0] == givenBoard[1][1] && givenBoard[1][1] == givenBoard[2][2])
    {
        if(givenBoard[0][0] == 'X')
        {
            return 1;
        }
        else if(givenBoard[0][0] == 'O')
        {
            return 2;
        }
    }
    else if(givenBoard[2][0] == givenBoard[1][1] && givenBoard[1][1] == givenBoard[0][2])
    {
        if(givenBoard[2][0] == 'X')
        {
            return 1;
        }
        else if(givenBoard[2][0] == 'O')
        {
            return 2;
        }
    }
    //FULL BOARD
    else if(givenBoard[0][0] != ' ' && givenBoard[0][1] != ' ' && givenBoard[0][2] != ' ' && givenBoard[1][0] != ' ' 
    && givenBoard[1][1] != ' ' && givenBoard[1][2] != ' ' && givenBoard[2][0] != ' ' && givenBoard[2][1] != ' ' && givenBoard[2][2] != ' ')
    {
        return 3;
    }
    return 0;
}

//modify board printer to take in a 2d array instead of a regular array
    //givenBoard[1] -> givenBoard[0][0], givenBoard[2] -> givenBoard[0][1], etc
void boardPrinter(char givenBoard[3][3]) //fuction that takes a char array and prints the board
{
    printf("   | 0:| 1:| 2:|\n");
    printf("   +---+---+---+\n");
    printf("0: | %c | %c | %c | \n", givenBoard[0][0], givenBoard[0][1], givenBoard[0][2]);
    printf("   +-----------+\n");
    printf("1: | %c | %c | %c | \n", givenBoard[1][0], givenBoard[1][1], givenBoard[1][2]);
    printf("   +-----------+\n");
    printf("2: | %c | %c | %c | \n", givenBoard[2][0], givenBoard[2][1], givenBoard[2][2]);
    printf("   +-----------+\n");
}

//modify to work with a 2d array, take 2 user inputs from same scanf line to represent row and column
int playerVsPlayer() //player vs player game, prints who is the winner 
{
    //char gameBoard[9] = {'1','2','3','4','5','6','7','8','9'}; 
    //make a blank 2d array to represent the gameboard
    char gameBoard[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}; 
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
            int player1Row = 3;
            int player1Column = 3;
            while (1)
            {
                int player1RowInput = 3;
                printf("Player 1 Turn. Enter row: \n");
                scanf("%d", &player1RowInput);
                if (player1RowInput >= 0 && player1RowInput < 3)
                {
                    player1Row = player1RowInput;
                    break;
                }
                printf("INVALID RESPONSE\n");
                getchar();
            }
            while (1)
            {
                int player1ColumnInput = 3;
                printf("Player 1 Turn. Enter column: \n");
                scanf("%d", &player1ColumnInput);
                if (player1ColumnInput >= 0 && player1ColumnInput < 3)
                {
                    player1Column = player1ColumnInput;
                    break;
                }
                printf("INVALID RESPONSE\n");
                getchar();
            }
            if (gameBoard[player1Row][player1Column] == ' ')
            {
                gameBoard[player1Row][player1Column] = 'X';
                break;
            }
            printf("INVALID SPACE\n");
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
            int player2Row = 3;
            int player2Column = 3;
            while (1)
            {
                int player2RowInput = 3;
                printf("Player 2 Turn. Enter row: \n");
                scanf("%d", &player2RowInput);
                if (player2RowInput >= 0 && player2RowInput < 3)
                {
                    player2Row = player2RowInput;
                    break;
                }
                printf("INVALID RESPONSE\n");
                getchar();
            }
            while (1)
            {
                int player2ColumnInput = 3;
                printf("Player 2 Turn. Enter column: \n");
                scanf("%d", &player2ColumnInput);
                if (player2ColumnInput >= 0 && player2ColumnInput < 3)
                {
                    player2Column = player2ColumnInput;
                    break;
                }
                printf("INVALID RESPONSE\n");
                getchar();
            }
            if (gameBoard[player2Row][player2Column] == ' ')
            {
                gameBoard[player2Row][player2Column] = 'O';
                break;
            }
            printf("INVALID SPACE\n");
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
    //char gameBoard[9] = {'1','2','3','4','5','6','7','8','9'}; 
    char gameBoard[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    while(1)
    {
        //prints game board and current players turn, game board has numbers to indicate which spaces available, will be filled out with an X for player 1 or and O for computer
        //0:|[0][0]|[0][0]|[0][0]|
        //1:|[0][0]|[0][0]|[0][0]|
        //2:|[0][0]|[0][0]|[0][0]|
    //asks player 1 for input and checks validity
        boardPrinter(gameBoard);
        while (1)
        {
            int player1Row = 3;
            int player1Column = 3;
            while (1)
            {
                int player1RowInput = 3;
                printf("Player 1 Turn. Enter row: \n");
                scanf("%d", &player1RowInput);
                if (player1RowInput >= 0 && player1RowInput < 3)
                {
                    player1Row = player1RowInput;
                    break;
                }
                printf("INVALID RESPONSE\n");
                getchar();
            }
            while (1)
            {
                int player1ColumnInput = 3;
                printf("Player 1 Turn. Enter column: \n");
                scanf("%d", &player1ColumnInput);
                if (player1ColumnInput >= 0 && player1ColumnInput < 3)
                {
                    player1Column = player1ColumnInput;
                    break;
                }
                printf("INVALID RESPONSE\n");
                getchar();
            }
            if (gameBoard[player1Row][player1Column] == ' ')
            {
                gameBoard[player1Row][player1Column] = 'X';
                break;
            }
            printf("INVALID SPACE\n");
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
            int computerRowInput = rand() % 3; 
            int computerColumnInput = rand() % 3;
            if (gameBoard[computerRowInput][computerColumnInput] == ' ')
            {
                printf("%d %d\n", computerRowInput, computerColumnInput);
                gameBoard[computerRowInput][computerColumnInput] = 'O';
                break;
            }
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