/******************************************************************************
 * Program Name: Langton's Ant - Ant Class Specification File
 * Name: Nicole Reynoldson
 * Date: 7/5/19
 * Description: Ant class stores and manages the ants orientation and position
 * on the board, is responsible for taking steps and changing direction. Works
 * in conjunction with a board object to update and display the board. 
 * ***************************************************************************/
#include <iostream>
#include "ant.hpp"
#include <string>
using std::string;
using std::cout;
using std::endl;

/******************************************************************************
 * Description: Ant constructor takes 4 ints as parameters, setting the x and y
 * position of the ant and storing the rows and columns. The rows and columns
 * are also used to call the board constructor.
 * ***************************************************************************/
Ant::Ant(int r, int c, int x, int y) : antBoard(r, c)
{
	prevX = xPos = x;
	prevY = yPos = y;
	rows = r;
	cols = c;
	color = ' ';
	direction = NORTH;
	
	antBoard.setSquare(xPos, yPos, '*');
}

/******************************************************************************
 * Description: moveForward() does not have any parameters or return any value.
 * Depending on the current direction of the ant, the function will store the
 * previous location and update the x or y position member variables. The
 * function checks for edge or corner cases, and will wrap the ants position 
 * on the board if encountered.
 * ***************************************************************************/
void Ant::moveForward(void)
{
	prevY = yPos;
	prevX = xPos;

	if(direction == NORTH)
	{
		if(yPos == 0) 
		{
			yPos = rows - 1;
		}
		else
		{
			yPos -= 1;
		}
	}
	
	if(direction == EAST)
	{
		if(xPos == cols - 1) 
		{
			xPos = 0;
		}
		else 
		{
			xPos += 1;
		}
	}

	if(direction == SOUTH)
	{
		if(yPos == rows - 1) 
		{
			yPos = 0;
		}
		else 
		{
			yPos += 1;
		}
	}
	
	if(direction == WEST)
	{
		if(xPos == 0) 
		{
			xPos = cols - 1;
		}
		else 
		{
		xPos -= 1;
		}
	}

}


/******************************************************************************
 * Description: changeDirection() will change direction of the ant based on 
 * what is currently stored in the color member variable (color of the square
 * the ant is presently on). Ant will turn to the left if the square is black
 * or white if the square is white. It takes no parameters and returns no value.
 * ***************************************************************************/
void Ant::changeDirection(void)
{
	int temp = static_cast<int>(direction);

	if(color == ' ')
	{
		temp += 1;
		// If at maximum value for direction, wrap back around
		if(temp > 4)
		{
			temp = 1;
		}
	}
	else
	{
		temp -= 1;
		
		if(temp < 1)
		{
			temp = 4;
		}
	}
	
	direction = static_cast<Compass>(temp);
}


/******************************************************************************
 * Description: makeMove() takes care of coordinating all movements together 
 * and updating the board. Takes no return type and returns no values. First 
 * the moveForward() function is called and the ant is wrapped if it is in a
 * position and direction where it could move off the board. Previous ant 
 * square color is updated, color of new square is stored while ant is occupies
 * the space. The ants position is then updated on the board and direction is
 * changed according to square color.
 * ***************************************************************************/
void Ant::makeMove(void)
{
	moveForward();
		
	// Change the previous location of ant to opposite color
	if(color == ' ')
	{
		antBoard.setSquare(prevX, prevY, '#');
	}
		
	else
	{
		antBoard.setSquare(prevX, prevY, ' ');
	}

	// Update the color variable to store the new location square color
	color = antBoard.getSquare(xPos, yPos);
	
	// Update the ants current location on the board
	antBoard.setSquare(xPos, yPos, '*');

	changeDirection();

}

/******************************************************************************
 * Description: Displays the current state of the board and ant direction.
 * ***************************************************************************/
void Ant::display(void)
{
	string directions[] = {" ", "North", "East", "South", "West"};
	cout << "\nDirection: " << directions[static_cast<int>(direction)] << endl;

	antBoard.displayBoard();
}
