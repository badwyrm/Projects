/*---  hanoi.cpp ----------------------------------------------------------
   Program to solve the Towers of Hanoi puzzle recursively.

   Input:  numDisks, the number of disks to be moved
   Output: A sequence of moves that solve the puzzle

   Written by:   Larry R. Nyhoff
   
   Written for:  Lab Manual for ADTs, Data Structures, and Problem
                 Solving with C++, 2E

                            Lab #9.1
                                                          
   Add your name here and other info requested by your instructor.
   
 -------------------------------------------------------------------------*/
#include "Timer.h"
#include <iostream>
#include <iomanip>
using namespace std;

void move(unsigned n, unsigned & moveNumber,
          char source, char destination, char spare);
Timer t;
int main()
{
	
   const char PEG1 = 'A',           // the three pegs
              PEG2 = 'B',
              PEG3 = 'C';
   unsigned moveNumber = 0;         // counts the moves

   cout << "This program solves the Hanoi Towers puzzle.\n\n";
   cout << "Enter the number of disks: ";
   unsigned numDisks;               // the number of disks to be moved
   cin >> numDisks;
   cout << endl;
   t.start();
   move(numDisks, moveNumber, PEG1, PEG3, PEG2); // the solution
   t.stop();
   cout << "Time taken: " << t << " secs" << endl;
}

void move(unsigned n, unsigned & moveNumber,
          char source, char destination, char spare)
/*-------------------------------------------------------------------------
  Recursive function to solve the Towers of Hanoi puzzle with n disks.

  Precondition:  None.
  Postcondition: A message describing the move is output to cout.
 ------------------------------------------------------------------------*/
{
  if (n == 1)                         // anchor
  {
    moveNumber++;
    cout << setw(3) << moveNumber 
         <<  ". Move the top disk from " << source  
         << " to " << destination << endl;
  }
  else
  {                                   // inductive case
    move(n-1, moveNumber, source, spare, destination);
    move(1, moveNumber, source, destination, spare);
    move(n-1, moveNumber, spare, destination, source);
  }
}
