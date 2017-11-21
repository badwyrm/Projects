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
int numCalls = 0;
int indent = -2;


// PUT PROTOTYPE OF recFibonacci HERE
int recFibonacci(int number);
/*-----------------------------------------------------------
  recFibonacci is a recursive Fibonacci number calculator.
 
  Precondition:  The parameter nis a positive integer.
  Postcondition: The n-th Fibonacci number is returned.
 ------------------------------------------------------------*/

int main()
{
  int n;

  for (;;)
  {
    cout << "\nPlease enter a positive integer (or 0 to stop): ";
    cin >> n;

    if (n <= 0) break;

    cout << "The " << n << "-th Fibonacci number is "
         << recFibonacci(n) << endl;
	cout << "Number of function calls: " << numCalls << endl;
  }
}

// DEFINE recFibonacci() HERE
int recFibonacci(int n) //1
{
	numCalls++;
	indent += 2;
	for (int i = 0; i <= indent; i++)
	{
		cout << " ";
	}
	cout << "-> entering f(" << n << ")" << endl;
	if (n == 0) //2
	{ 
		indent =- 2;
		cout << "<- f(" << n << ") returns 0" << endl;
			
		return 0;
	}
		if (n == 1) //3
		{ 
			indent =- 2;
			cout << "<- f(" << n << ") returns 1" << endl;;
			return 1;
		}
	else
		cout << "<- f(" << n << ") returns " << recFibonacci(n - 1) + recFibonacci(n - 2) << endl;
		indent -= 2;
		return recFibonacci(n - 1) + recFibonacci(n - 2); //4
}

