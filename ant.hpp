/******************************************************************************
 * Program Name: Langton's Ant - Ant Class Declaration File
 *	Name: Nicole Reynoldson
 *	Date: 7/5/19
 * Description: Ant class stores and manages the ants orientation and position
 * on the board, is responsible for taking steps and changing direction. Works
 * in conjunction with a board object to update and display the board. 
 * ***************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP
#include "board.hpp"

enum Compass {NORTH = 1, EAST, SOUTH, WEST};

class Ant
{
	private:
		int xPos, yPos, prevX, prevY, rows, cols;
		char color;	// Holds the color the square occupied by the ant
		Compass direction;
		Board antBoard;
		// Moves the ant forward a step or wraps the ant
		void moveForward(void);
		// Changes the ant direction based on current square color
		void changeDirection(void);

	public:
		Ant(int, int, int, int);
		// Coordinates forward step, wrapping, changing position,
		// direction, square colors and updating the board
		void makeMove(void);
		void display(void);
};

#endif
		
