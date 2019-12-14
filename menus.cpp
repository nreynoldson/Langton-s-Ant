/******************************************************************************
 * Program Name: Langton's Ant - Menu Functions
 * Name: Nicole Reynoldson
 * Date: 7/5/19
 * Description: Display for start and end menu of Langton's Ant simulator
 * ***************************************************************************/

#include "menus.hpp"
#include <iostream>
using std::cout;
using std::endl;

// Prints the starting menu to the screen
void displayStartMenu()
{
	cout << "1. Start Langton's Ant Simulation" << endl;
	cout << "2. Quit" << endl;
}

// Prints the menu for when simulation has completed
void displayEndMenu()
{
	cout << "\n1. Play again?" << endl;
	cout << "2. Quit" << endl;
}
