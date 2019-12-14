/******************************************************************************
 * Program Name: Langton's Ant - Board Class Declaration File
 * Name: Nicole Reynoldson
 * Date: 7/5/19
 * Description: Board class responsible for dynamically allocating a matrix to 
 * represent the board and storing the characters at each square.
 *****************************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
	private:
		int rows, cols;
		char **board;

	public:
		Board(int, int);
		void setSquare(int, int, char);
		char getSquare(int, int);
		void displayBoard(void);
		~Board();
};

#endif
