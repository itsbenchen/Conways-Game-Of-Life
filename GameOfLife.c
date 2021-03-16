/* Extra Credit Lab Project for ICS 53L ; Conway's Game of Life */ 

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

// pre-defined Rows and Columns (Can be changed)
#define ROWS 50
#define COLUMNS 150

// pre-defined to differentiate between Alive and Dead states
#define ALIVE 1
#define DEAD 0

// Char representation of dead and alive states

const char deadSymbol = '.';
const char aliveSymbol = '*';

// The 2-D array for the game
int gameBoard[ROWS][COLUMNS];

void fillBoard(int rows, int columns, int board[][columns])
{
	/* Given the number of rows and columns and the board, fill the cells with 0s and 1s. */

	srand(time(0)); // Utilizes a random seed every time this function is called

	for (int i = 1; i < rows - 1; ++i)
		for (int j = 1; j < columns - 1; ++j)
			board[i][j] = rand() % 2;
}

void clearBoard(int rows, int columns, int board[][columns])
{
	/* Clears the board by setting each cell to DEAD (0) state */
        for (int i = 0; i < rows; ++i)
                for (int j = 0; j < columns; ++j)
                        board[i][j] = DEAD;
}

void copyBoard(int rows, int columns, int newBoard[][columns], int oldBoard[][columns])
{
	/* Copies the game board from one to another */
	for (int i = 0; i < rows; ++i)
                for (int j = 0; j < columns; ++j)
                        newBoard[i][j] = oldBoard[i][j];
	
}

void printBoard(int rows, int columns, int board[][columns])
{
	/* Prints out the board onto console. */
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			if (board[i][j] == 1) {
				printf("%c", aliveSymbol);
			}
			else if (board[i][j] == 0) {
				printf("%c", deadSymbol);
			}
		}
		printf("\n");
	}
}

void applyGameLogic(int rows, int columns, int board[][columns])
{	
	/* Game logic for Conway's Game of Life 
		Applies game logic to the inserted board and prints it out after
		Rules:
		For each cell:
			1. If an alive cell has less than 2 ALIVE neighbors, it dies.
				(Under population)
			2. If an alive cell is with 2 or 3 neighbors, it stays ALIVE.
				(Lives on)
			3. if an alive cell is with more than three ALIVE neighbors, it dies.
				(Overpopulation)
			4. Any dead cell is with 3 ALIVE neighbors will become alive too.
				(Reproduction) 
	
	*/

	int tempBoard[rows][columns];
	clearBoard(rows, columns, tempBoard);
	
	// Loop through the inner grids and find ALIVE neighbors for each cell
	for (int i = 1; i < rows - 1; ++i)
	{
		for (int j = 1; j < columns - 1; ++j)
		{
			int neighborsAlive = 0;
			// Finds all ALIVE neighbors by checking the it's surrounding neighbors
			for (int a = -1; a <= 1; ++a) {
				for (int b = -1; b <= 1; ++b) {
						neighborsAlive += board[i + a][j + b];
				}
			}

			// Exclude the cell itself (a = 0, b = 0)
			if (board[i][j] == ALIVE) {
				neighborsAlive -= board[i][j];
			}
			
				
			if (board[i][j] == ALIVE)
			{
				// Rule 1
				if (neighborsAlive < 2)
					tempBoard[i][j] = DEAD;
				// Rule 2
				else if (neighborsAlive == 2 || neighborsAlive == 3)
					tempBoard[i][j] = ALIVE;
				// Rule 3
				else if (neighborsAlive > 3) {
					tempBoard[i][j] = DEAD;
				}
			} 
			// Rule 4
			else if (board[i][j] == DEAD)
				if (neighborsAlive == 3)
					tempBoard[i][j] = 1;

		}
	}
	printBoard(rows, columns, tempBoard);
	copyBoard(rows, columns, board, tempBoard);
}

void gameLoop(int rows, int columns, int board[][columns]) {
	while(1) {
		system("CLS"); // VS Code to clear the terminal
		applyGameLogic(rows, columns, board);
		sleep(1); // Pause program to see the change at the set interval
	}
}

int main()
{
	fillBoard(ROWS, COLUMNS, gameBoard);	// Fills the game board with random 0s and 1s
	printf("Conway's Game of Life (C implementation)\n");
	printf("Initial Board:\n");
	printBoard(ROWS, COLUMNS, gameBoard);	// Prints out current state of board
	int seconds = 3; // Seconds to pause before game starts
	printf("Starting in %i seconds...\n", seconds);
	sleep(seconds);
	gameLoop(ROWS, COLUMNS, gameBoard);
	return 0;
}