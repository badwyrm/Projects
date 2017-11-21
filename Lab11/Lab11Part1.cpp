/*--- rectester.cpp -------------------------------------------------------
  Program to test a recursive Fibonacci function.
   
  Written by:   Larry R. Nyhoff
   
  Written for:  Lab Manual for ADTs, Data Structures, and Problem
                Solving with C++, 2E

                            Lab #8.1
                                                          
  Add your name here and other info requested by your instructor.
  
 --------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

//-- PUT THE GLOBAL VARIABLE DECLARATIONS HERE
int indent = -2;

// PUT PROTOTYPE OF recFibonacci HERE

int f(int n);
int main()
{
  int n;
  cout << "\nPlease enter a positive integer: ";
  cin >> n;
  cout << "The function equates to " << f(n) << endl;
  
}


int f(int n)
{
	indent += 2;
	for (int i = 0; i < indent; i++)
	{
		cout << " ";
	}
	cout << "-> entering f(" << n << ")" << endl;
	if (n < 2) //2 
	{ 
		indent -= 2;
		cout << "<- f(" << n << ") returns 0" << endl;

		return 0; //3
		
	}
	else
	{
		cout << "<- f(" << n << ") returns " << (1 + f(n / 2)) << endl;
		indent -= 2;
		return 1 + f(n / 2);//4
	}
}
