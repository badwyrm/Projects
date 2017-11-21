/*--- geology.cpp ---------------------------------------------------
  A program to model rocks.
 
  Written by:   Larry R. Nyhoff
  Written for:  Lab Manual for ADTs, Data Structures, and Problem
                Solving with C++, 2E

                     Lab #2.2  and  Project #2.2	

  Add your name here and other info requested by your instructor.
  
---------------------------------------------------------------------*/

#include <iostream>
#include "Rock(lab2.2).h"
using namespace std;

// Represent each rock by a number

/*const int BASALT = 0;
const int DOLOMITE = 1;
const int GRANITE = 2;
const int GYPSUM = 3;
const int LIMESTONE = 4;
const int MARBLE = 5;
const int OBSIDIAN = 6;
const int QUARTZITE = 7;
const int SANDSTONE = 8;
const int SHALE = 9;
const int ROCK_OVERFLOW = 10;*/



// Function prototypes go here

int main()
{
  /***** PART 1 ******/

  // Declare a variable to store a rock

  Rock sample;

  // Input and display various rocks

  for(;;)
  {
    cout << "Enter a rock (" << ROCK_OVERFLOW << " to stop): ";
	int temp; cin >> temp;
	sample = Rock(temp);
    if (sample == ROCK_OVERFLOW) break;
    cout << "Rock is: " << sample << endl;
	
  }

  /***** PART 2 ******/

  // Display all the rock names

  cout << "\nList of rocks:\n";
  for (Rock rockVal = BASALT; rockVal < ROCK_OVERFLOW; rockVal = nextOne(rockVal))
  {
	  cout << rockVal << "  ";
	  cout << kind(rockVal) << endl;
  }
  cout << endl;
}
