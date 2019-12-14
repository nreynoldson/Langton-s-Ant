/*****************************************************************************
 * Program Name: Langton's Ant - getInput() Function Source File
 * Name: Nicole Reynoldson
 * Date: 7/5/19
 * Description: This function gets input from the user and validates it. Two 
 * ints are taken as parameters and are used to determine the range of valid 
 * values. The target type must be an integer. Once validated, the integer
 * value is returned.
 * ***************************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "getInput.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int getInput(int min, int max)
{
	string input; //User choice is taken as a string
	char * endPtr;
	int integerVal;
	bool flag = false; // Set to false while input is not valid

// Adapted from:  https://arstechnica.com/civis/viewtopic.php?f=20&t=868003
	while(flag == false)
	{
		// Get the full line of input and convert to an integer value
		getline(cin, input);
		integerVal = static_cast<int>(strtol(input.c_str(), &endPtr, 10));
	
		// endPtr points to last non-digit value, if it is anything other
		// than the null character, it is not a valid input
		if(*endPtr == '\0')
		{
			// Then check that converted type is within the specified range
			if(integerVal <= max && integerVal >= min)
			{
				flag = true;
			}
			else
			{
				cout << "You must enter an integer value between " << min
					  << " and " << max << ". Try again." << endl;
			}
		}
		else
		{
			cout << "Incorrect data type. You must enter an integer between "
				  << min << " and " << max << ". Try again. " << endl;
		}
	}
	
	return integerVal;
}

