/******************************************************************************
 * Program Name: Langton's Ant - Board Class Specification file
 * Name: Nicole Reynoldson
 *	Date: 7/5/19 
 * Description: Board class responsible for dynamically allocating a matrix to 
 * represent the board and storing the characters at each square.
 * ****************************************************************************/

#include <iostream>
#include "board.hpp"
using std::endl;
using std::cout;

/*******************************************************************************
 * Description: Board constructor takes two ints as parameters to set the row
 * and column member variables. The function dynamically allocates memory for
 * and array to hold characters representing the board colors and ant. It then
 * initializes all characters of the array to white (ie. ' ') 
 * ****************************************************************************/
Board::Board(int r, int c)
{
	rows = r;
	cols = c;
	
	// Dynamically allocate a 2D array to represent the board
	board = new char*[rows];
	for(int i = 0; i < rows; i++)
		board[i] = new char[cols];

	// Initialize each element of the array to a white square (' ')
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			board[i][j] = ' ';
		}
	}
}

/*******************************************************************************
 * Description: Takes 2 ints for row and column of the square whose color is to
 * be changed as parameters. Also takes a char to fill the element. Does not
 * return a value.
 * ****************************************************************************/
void Board::setSquare(int x, int y, char color)
{
	board[y][x] = color;
}


/*******************************************************************************
 * Description: Takes 2 ints for the row and column of the square and returns 
 * a char representing the color at that position. 
 * ****************************************************************************/
char Board::getSquare(int x, int y)
{
	return board[y][x];
}


/*******************************************************************************
 * Description: Takes no parameters and does not return any values. This 
 * function iterates through all elements of the board and displays them to the
 * screen. 
 * ****************************************************************************/
void Board::displayBoard(void)
{
	for(int i = 0; i < cols + 2; i++)
		cout << "-";
	cout << endl;
	
	for(int i = 0; i < rows; i++)
	{
		cout << "|";
		for(int j = 0; j < cols; j++)
			cout << board[i][j];
		cout << "|" << endl;
	}
	
	for(int i = 0; i < cols + 2; i++)
		cout << "-";
	cout << endl;
}

/*******************************************************************************
 * Description: Board destructor frees the memory that was allocated for the 
 * board.
 * ****************************************************************************/
Board::~Board()
{
	for(int i = 0; i < rows; i++)
	{
		delete [] board[i];
	}
	delete [] board;
}

