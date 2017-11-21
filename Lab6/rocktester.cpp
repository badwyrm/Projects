/*--- rocktester.cpp ----------------------------------------------------
  A program for testing type Rock.

  Written by:   Larry R. Nyhoff
  Written for:  Lab Manual for ADTs, Data Structures, and Problem
                Solving with C++, 2E

                      Lab #4.1 & Project #4.1

  Add your name here and other info requested by your instructor.
  
 ----------------------------------------------------------------------*/

#include <iostream>
using namespace std;


#include "Rock.h"

//********* BEGIN PART 1 **********
//----- Testing redeclaration prevention

#include "Rock.h"

//********** END PART 1  **********/


int main()
{
//-------- BEGIN PART 0 ----------
  cout << "\n=============================================\n"
          "    PART 0:  Testing placement of enumeration"
          "\n=============================================\n";
  cout << GRANITE << endl;

//--------- END PART 0  ----------


//********* BEGIN PART 2 **********
  cout << "\n=======================================\n"
          "    PART 2:  Testing the constructor(s)"
          "\n=======================================\n";
  Rock sample,
       rockVal(GRANITE);

  //********** END PART 2  **********/

//********* BEGIN PART 3 **********
  cout << "\n===========================================\n"
          "    PART 3:  Testing function member display()"
          "\n===========================================\n";
  cout << "Value of\n"
       << "  sample is....";
  sample.display(cout);
  cout << endl;
  cout << "  rockVal is...";
  rockVal.display(cout);
  cout << endl;

  //********** END PART 3  **********/


//********* BEGIN PART 4 **********

  cout << "\n========================================\n"
          "    PART 4:  Testing the output operator"
          "\n========================================\n";
  cout << "Value of\n"
       << "  sample is...." << sample << endl
       << "  rockVal is..." << rockVal << endl;

  //********** END PART 4  **********/


//********* BEGIN PART 5 **********

  cout << "\n=========================================\n"
           "     PART 5:  Testing the input operator"
           "\n=========================================\n";

  cout << "Enter two rock names: ";
  cin >> sample >> rockVal;
  cout << "First rock is...." << sample << endl
       << "Second rock is..." << rockVal << endl;

  //********** END PART 5  **********/


//********* BEGIN PART 6 **********

  cout << "\n=============================================\n"
          "     PART 6:  Testing the rock-kind operator"
          "\n=============================================\n";

  char response;
  do
  {
    cout << "Enter a rock name: ";
    cin >> sample;
    cout << "Kind of " << sample << " is " << sample.kind() << endl;
    cout << "More rocks (Y or N)? ";
    cin >> response;
  }
  while (response == 'Y' || response == 'y');

  //********** END PART 6  **********/

//********* BEGIN PART 7 **********

  cout << "\n================================================\n"
          "     PART 7:  Testing the rock-texture operator"
          "\n================================================\n";
  do
  {
    cout << "Enter a rock name: ";
    cin >> sample;
    cout << "Texture of " << sample << " is " << sample.texture() << endl;
    cout << "More rocks (Y or N)? ";
    cin >> response;
  }
  while (response == 'Y' || response == 'y');

  //********** END PART 7  **********/


//********* BEGIN PART 8 *********
  cout << "\n================================================\n"
		  "     PART 8:  Accessor Functions"
		  "\n================================================\n";

  cout << "Enter a rock name: ";
  cin >> sample;
  sample.name();

//******** END PART 8  **********


//********* BEGIN PART 9 **********

  cout << "\n=====================================================\n"
          "     PART 9:  Testing == and < with two Rock objects"
          "\n=====================================================\n";

  Rock rock1(GRANITE),
       rock2(MARBLE),
       rock3(MARBLE);

  cout << "rock1 = " << rock1 << "  rock2 = " << rock2
       << "  rock3 = " << rock3 << endl;
  cout << boolalpha;                                                            
  cout << "rock1 < rock2? " << (rock1 < rock2) << endl;                         
  cout << "rock1 == rock2? " << (rock1 == rock2) << endl;                       
  cout << "rock2 < rock3? " << (rock2 < rock3) << endl;                        
  cout << "rock2 == rock3? " << (rock2 == rock3) << endl;                    

//********** END PART 9  **********/


//********* BEGIN PART 10 **********

  cout << "\n============================================================\n"
          "     PART 10:  Testing == and < with a Rock and a RockName"
          "\n============================================================\n";

  cout << "rock1 = " << rock1 << endl;
  cout << "rock1 < MARBLE? " << (rock1 < MARBLE ? "Yes" : "No")  << endl;
  cout << "rock1 == GRANITE? " << (rock1 == GRANITE ? "Yes" : "No")  << endl;

//********** END PART 10  **********/
}
