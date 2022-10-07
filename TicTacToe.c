#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Description: Tic Tac Toe game between 2 players or player vs computer

//modify win checker by changing it to take in and check a 2d array 
    //givenBoard[1] -> givenBoard[0][0], givenBoard[2] -> givenBoard[0][1], etc
int winChecker(char givenBoard[3][3]) //function that checks if there is a winner based on inputted array, returns a number for use in playerVsPlayer() and playerVsComputer()
{ 
    //if else statements check if a row, column, or diagonal equal
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
void boardPrinter(char givenBoard[3][3]) //fuction that takes a 2d char array and prints a board based on the 2d array
{
    //prints game board, will be filled out with an X for player 1  and O for player 2 and the computer
    //gameboard will be filled out by playerVsPlayer() or playerVsComputer()
        //  |   0: |  1:  |   2: |
        //0:|[0][0]|[0][0]|[0][0]|
        //1:|[0][0]|[0][0]|[0][0]|
        //2:|[0][0]|[0][0]|[0][0]|
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
int playerVsPlayer() //player vs player game, prints who is the winner or draw based on winChecker()'s return value
{
    //make a blank 2d array to represent the gameboard
    char gameBoard[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}; 
    //encase in while loop for game duration, ends if there is a winner or draw
    while(1)
    {
        //asks player 1 for input and checks validity
        //PLAYER 1 TURN
        boardPrinter(gameBoard); //print intial empty gameBoard
        while (1)
        {
            int player1Row = 3; //player1Row set to 3 so will fail and stay in loop 
            int player1Column = 3; //player1Column set to 3 so will fail and stay in loop
            //ROW INPUT
            while (1) 
            {
                int player1RowInput = 3; //player1RowInput set to 3 to stay in loop and prevent a bug
                printf("Player 1 Turn. Enter row: \n");
                scanf("%d", &player1RowInput); //get user row input
                if (player1RowInput >= 0 && player1RowInput < 3) //check if user input is within the array 
                {
                    player1Row = player1RowInput; //set player1Row to player1RowInput
                    break; //break out of the question loop if user input valid
                }
                printf("INVALID RESPONSE\n"); //prints error message if user input not useable in the 2d array
                getchar(); //prevent char input from ending program prematurely 
            }
            //COLUMN INPUT
            while (1)
            {
                int player1ColumnInput = 3; //player1Column set to 3 so will fail and stay in loop 
                printf("Player 1 Turn. Enter column: \n");
                scanf("%d", &player1ColumnInput); //get user column input
                if (player1ColumnInput >= 0 && player1ColumnInput < 3) //check if user input is within the array 
                {
                    player1Column = player1ColumnInput; //set player1Column to player1ColumnInput 
                    break; //break out of the question loop if user input valid
                }
                printf("INVALID RESPONSE\n"); //prints error message if user input not useable in the 2d array
                getchar(); //prevent char input from ending program prematurely 
            }
            if (gameBoard[player1Row][player1Column] == ' ') //checks if gameBoard space is empty
            {
                gameBoard[player1Row][player1Column] = 'X'; //If empty, fills in the space with an X based on player1Row and player1Column 
                break; //break out of the loop to move on to winChecker()
            }
            printf("INVALID SPACE\n"); //print INVALID SPACE message if space already filled
        }
        //WIN CHECK
        //runs win checker to see if there is a winner or draw
        if(winChecker(gameBoard) == 1) //checks if winChecker returns 1 = player 1 win
        {
            printf("Player 1 wins!\n"); //print player 1 win message
            break; //break out of loop to end function
        }
        else if(winChecker(gameBoard) == 2) //checks if winChecker returns 2 = player 2 win
        {
            printf("Player 2 wins!\n"); //print player 2 win message
            break; //break out of loop to end function
        }
        else if(winChecker(gameBoard) == 3) //checks if winChecker returns 3 = draw
        {
            printf("Draw!\n"); //print draw message
            break; //break out of loop to end function
        }

        //PLAYER 2 TURN
        boardPrinter(gameBoard);
        while (1)
        {
            int player2Row = 3; //player2Row set to 3 so will fail and stay in loop
            int player2Column = 3; //player2Column set to 3 so will fail and stay in loop
            //ROW INPUT
            while (1)
            {
                int player2RowInput = 3; //player2RowInput set to 3 to stay in loop and prevent a bug
                printf("Player 2 Turn. Enter row: \n"); 
                scanf("%d", &player2RowInput); //get user row input
                if (player2RowInput >= 0 && player2RowInput < 3) //check if user input is within the array 
                {
                    player2Row = player2RowInput; //set player2Row to player2RowInput
                    break; //break out of the question loop if user input valid
                }
                printf("INVALID RESPONSE\n"); //prints error message if user input not useable in the 2d array
                getchar(); //prevent char input from ending program prematurely 
            }
            //COLUMN INPUT
            while (1)
            {
                int player2ColumnInput = 3; //player2Column set to 3 so will fail and stay in loop 
                printf("Player 2 Turn. Enter column: \n");
                scanf("%d", &player2ColumnInput); //get user column input
                if (player2ColumnInput >= 0 && player2ColumnInput < 3) //check if user input is within the array 
                {
                    player2Column = player2ColumnInput; //set player2Column to player2ColumnInput 
                    break; //break out of the question loop if user input valid
                }
                printf("INVALID RESPONSE\n"); //prints error message if user input not useable in the 2d array
                getchar(); //prevent char input from ending program prematurely 
            }
            if (gameBoard[player2Row][player2Column] == ' ') //checks if gameBoard space is empty
            {
                gameBoard[player2Row][player2Column] = 'O'; //If empty, fills in the space with an X based on player2Row and player2Column 
                break; //break out of the loop to move on to winChecker
            }
            printf("INVALID SPACE\n"); //print INVALID SPACE message if space already filled
        }
        //WIN CHECK
        //runs win checker to see if there is a winner or draw
        if(winChecker(gameBoard) == 1) //checks if winChecker returns 1 = player 1 win
        {
            printf("Player 1 wins!\n"); //print player 1 win message
            break; //break out of loop to end function
        }
        else if(winChecker(gameBoard) == 2) //checks if winChecker returns 2 = player 2 win
        {
            printf("Player 2 wins!\n"); //print player 2 win message
            break; //break out of loop to end function
        }
        else if(winChecker(gameBoard) == 3) //checks if winChecker returns 3 = draw
        {
            printf("Draw!\n"); //print draw message
            break; //break out of loop to end function
        }
    }
    return 0;
}
//modify to work with a 2d array, take 2 user inputs from same scanf line to represent row and column
int playerVsComputer() //player vs computer game, prints who is the winner, computer picks random numbers
{
    //copy most of the code from player vs player, modify player 2 section 
    char gameBoard[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    //encase in while loop for game duration, ends if there is a winner or draw 
    while(1)
    {
        //PLAYER 1 TURN
        boardPrinter(gameBoard);
        while (1)
        {
            int player1Row = 3; //player1Row set to 3 so will fail and stay in loop 
            int player1Column = 3; //player1Column set to 3 so will fail and stay in loop
            //ROW INPUT
            while (1) 
            {
                int player1RowInput = 3; //player1RowInput set to 3 to stay in loop and prevent a bug
                printf("Player 1 Turn. Enter row: \n");
                scanf("%d", &player1RowInput); //get user row input
                if (player1RowInput >= 0 && player1RowInput < 3) //check if user input is within the array 
                {
                    player1Row = player1RowInput; //set player1Row to player1RowInput
                    break; //break out of the question loop if user input valid
                }
                printf("INVALID RESPONSE\n"); //prints error message if user input not useable in the 2d array
                getchar(); //prevent char input from ending program prematurely 
            }
            //COLUMN INPUT
            while (1)
            {
                int player1ColumnInput = 3; //player1Column set to 3 so will fail and stay in loop 
                printf("Player 1 Turn. Enter column: \n");
                scanf("%d", &player1ColumnInput); //get user column input
                if (player1ColumnInput >= 0 && player1ColumnInput < 3) //check if user input is within the array 
                {
                    player1Column = player1ColumnInput; //set player1Column to player1ColumnInput 
                    break; //break out of the question loop if user input valid
                }
                printf("INVALID RESPONSE\n"); //prints error message if user input not useable in the 2d array
                getchar(); //prevent char input from ending program prematurely 
            }
            if (gameBoard[player1Row][player1Column] == ' ') //checks if gameBoard space is empty
            {
                gameBoard[player1Row][player1Column] = 'X'; //If empty, fills in the space with an X based on player1Row and player1Column 
                break; //break out of the loop to move on to winChecker()
            }
            printf("INVALID SPACE\n"); //print INVALID SPACE message if space already filled
        }
        //WIN CHECK
        //runs win checker to see if there is a winner or draw
        if(winChecker(gameBoard) == 1) //checks if winChecker returns 1 = player 1 win
        {
            printf("Player 1 wins!\n"); //print player 1 win message
            break; //break out of loop to end function
        }
        else if(winChecker(gameBoard) == 2) //checks if winChecker returns 2 = player 2 win
        {
            printf("Player 2 wins!\n"); //print player 2 win message
            break; //break out of loop to end function
        }
        else if(winChecker(gameBoard) == 3) //checks if winChecker returns 3 = draw
        {
            printf("Draw!\n"); //print draw message
            break; //break out of loop to end function
        }

    //computer randomly generates a number, if number is invalid regenerates a number
    //COMPUTER TURN
    printf("Computer Turn: \n");
        while (1)
        {
            srand(time(NULL)); //function to make rand() not generate in a fixed pattern
            int computerRowInput = rand() % 3; //generate a random number from 0-2 for the column row
            int computerColumnInput = rand() % 3; //generate a random number from 0-2 for the column
            if (gameBoard[computerRowInput][computerColumnInput] == ' ') //checks if space on the board is empty
            {
                printf("Row: %d Column: %d\n", computerRowInput, computerColumnInput); //if empty, prints computer's answer
                gameBoard[computerRowInput][computerColumnInput] = 'O'; //fills in the space with an O based on computerRowInput and computerColumnInput
                break; //break out of loop to end computer's turn
            }
        }
        //runs win checker to see if there is a winner or draw
        //WIN CHECK
        //runs win checker to see if there is a winner or draw
        if(winChecker(gameBoard) == 1) //checks if winChecker returns 1 = player 1 win
        {
            printf("Player 1 wins!\n"); //print player 1 win message
            break; //break out of loop to end function
        }
        else if(winChecker(gameBoard) == 2) //checks if winChecker returns 2 = player 2 win
        {
            printf("Player 2 wins!\n"); //print player 2 win message
            break; //break out of loop to end function
        }
        else if(winChecker(gameBoard) == 3) //checks if winChecker returns 3 = draw
        {
            printf("Draw!\n"); //print draw message
            break; //break out of loop to end function
        }
    }
    return 0;
}

int main()
{
    int userPlayAgain = 1; //set userPlayAgain as 1 so it is always true
    while (userPlayAgain == 1)
    {
        int userGamePick = 3; //int for if user wants to player vs player or player vs computer
        int userInputPlayAgain = 3; //int for if user wants to play again
        //int pickGameStatus = 1; //int for while loop, if while loop is 1
        printf("WELCOME TO TIC TAC TOE!\n");
        
    
        //prompt user for game they wish to play, encase in loop, break if user inputs a valid unput
        //read information from console, 1 = player vs player, 2 = player vs computer, anything else = invalid input
            //else, print invalid input and ask for input again
        while (1) //while loop for getting user input
        {
            int userGameInput; //int for storing user input
            printf("1: Person vs. Person\n");
            printf("2: Person vs. Computer\n");
            printf("Enter your choice (1 or 2): \n");
            scanf("%d", &userGameInput); //get user input
            if (userGameInput == 1 || userGameInput == 2) //check if user input is a 1 or 2
            {
                userGamePick = userGameInput; //if true, set userGamePick to userGameInput
                break; //break out of loop to end question
            }
            printf("INVALID RESPONSE\n"); //print invalid response if user inputs an invalid answer
            getchar(); //prevent char input from ending program prematurely 
        }
        //if 1 is chosen, break out of loop, starts player v player game as playerVsPlayer() function
        if (userGamePick == 1)
        {
            printf("You have entered choice 1, player vs player.\n");
            playerVsPlayer();
        }
        //if 2 is chosen, break out of loop, start player vs computer game as playerVsComputer() function
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
            scanf("%d", &userInputPlayAgain); //get user input
            if (userInputPlayAgain == 1) //check if user input is 1 
            {
                break; //if true, break out of question loop, reruns game since program is encased in another while loop
            }
            if (userInputPlayAgain == 2) //checks if user input is 2
            {
                printf("Goodbye. \n"); 
                userPlayAgain = 2; //sets userPlayAgain to 2 to break out of main loop that encases the program
                break; //break out of question loop
            }
            printf("INVALID RESPONSE\n"); //prints INVALID message if user input not possible
            getchar(); //prevent char input from ending program prematurely 
        }   
    }
    return 0;
}