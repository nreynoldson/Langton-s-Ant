/******************************************************************************
 * Program Name: Langton's Ant - randLoc() Function Source - For extra credit
 * Name: Nicole Reynoldson
 * Date: 7/6/19
 * Description: randLoc() takes two integers as the minimum and maximum values
 * of the range for which random numbers can be generated. The value is then 
 * returned as an integer.
 * ***************************************************************************/
#include "randLoc.hpp"
#include <ctime>
#include <cstdlib>

int randLoc(int min, int max)
{
	srand(time(0));
	return (rand() % (max - min + 1) + min);
}

