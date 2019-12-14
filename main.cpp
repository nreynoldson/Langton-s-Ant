/******************************************************************************
 * Program Name: Langton's Ant - Plus Extra Credit
 * Name: Nicole Reynoldson
 * Date: 7/5/19
 * Description: Langton't ant follows basic rules: the ant makes a step forward,
 * previous square color is inverted, the ant will turn left if it has stepped
 * on a black square or right if it has stepped on a white square.
 *
 * This version allows the user to specify board size,and the number of steps 
 * in the simulation. The starting location of the ant may be random or chosen
 * by the user.
 * ***************************************************************************/
#include <iostream>
#include "getInput.hpp"
#include "menus.hpp"
#include "ant.hpp"
#include "randLoc.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	cout << "\nLangton's Ant Simulation" << endl;
	cout << "---------------------------------------------------------" << endl;

	int menuChoice, rows, cols, steps, maxSteps, xPos, yPos;
	bool simFinished = false; // Used to store the state of the game

	// If the user decides to quit, do not enter while loop and return from main
	displayStartMenu();
	menuChoice = getInput(1, 2);
	if(menuChoice == 2)
	{
		simFinished = true;
	}

	while(simFinished == false)
	{
		// Initialize or reset current steps depending on playthrough
		steps = 0;

		//Get settings for simulation
		cout << "\nSimulation Settings" << endl;
		cout << "-------------------------------------------------------" << endl;
		
		cout << "Rows on board: ";
		rows = getInput(1, 200);

		cout << "Columns on board: "; 
		cols = getInput(1, 200 );
		
		cout << "Ant starting position: " << endl;
		cout << "1. Random" << endl;
		cout << "2. User Choice" << endl;
		menuChoice = getInput(1, 2);

		//Set a random value for x and y position
		if(menuChoice == 1)
		{
			xPos = randLoc(0, cols - 1);
			yPos = randLoc(0, rows - 1);
		}
		else
		{
			cout << "\nStarting row: ";
			yPos = (getInput(1, rows)) - 1;

			cout << "Starting column: ";
			xPos = (getInput(1, cols)) - 1;
		}
		
		cout << "Steps in simulation: ";
		maxSteps = getInput(1, 30000);
	
		// Generate ant and board
		Ant anAnt(rows, cols, xPos, yPos);
	
		cout << "\nStarting simulation." << endl;
		cout << "-------------------------------------------------------" << endl;
	
		// Move ant until maximum steps are reached
		// display steps, direction and board for each move	
		while(steps <= maxSteps)
		{
			anAnt.display();
			cout << "Step: " << steps << endl;
			anAnt.makeMove();
			steps += 1;	
		}

		displayEndMenu();
		menuChoice = getInput(1, 2);

		// User quits, exit while loop and return from main
		if(menuChoice == 2)
		{
			simFinished = true;
		}
	}

	cout << "\nThank you for playing! Goodbye!" << endl;
	return 0;
}
			
