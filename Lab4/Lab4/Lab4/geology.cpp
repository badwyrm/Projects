/*--- geology.cpp ---------------------------------------------------
  A program to model rocks.
 
  Written by:   Larry R. Nyhoff
  Written for:  Lab Manual for ADTs, Data Structures, and Problem
                Solving with C++, 2E

                     Lab #2.2  and  Project #2.2	

Andrew Tran  
---------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
using namespace std;
#include "Rock.h"

int main()
{
  Rock sample;
  ifstream inFile("Rockfile.txt");
  if (!inFile) //close out if file fails
  {
	  cout << "Error opening file" << endl;
	  exit(1107);
  }
  int count[10] = { 0 };
  
  for(;;) //infinite loop to read file
  {
	inFile >> sample;
	count[sample]++; //increment matching array element (the rock) detected in file
	cout << "Rock counted is: " << sample << endl;
	if (inFile.eof()) //only break if it reaches end of file
		break;
  }
  cout << endl; 
  for (int i = 0; i < 10; i++) //print histogram
  {
	  int n = count[i]; 
	  string s(n, 'X'); //determines number of "x"
	  cout << static_cast<Rock>(i) << "    " << s << "    " << "(" << n << ")" << endl;
  }
}
