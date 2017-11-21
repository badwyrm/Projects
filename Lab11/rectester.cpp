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



// PUT PROTOTYPE OF recFibonacci HERE
int recFibonacci(int number);
/*-----------------------------------------------------------
  recFibonacci is a recursive Fibonacci number calculator.
 
  Precondition:  The parameter nis a positive integer.
  Postcondition: The n-th Fibonacci number is returned.
 ------------------------------------------------------------*/
int f(int n);
int main()
{
  int n;

  for (;;)
  {
    cout << "\nPlease enter a positive integer (or 0 to stop): ";
    cin >> n;

    if (n <= 0) break;

    cout << "The " << n << "-th Fibonacci number is "
         << f(n) << endl;
  }
}

// DEFINE recFibonacci() HERE
int recFibonacci(int n) //1
{
	if (n == 0) //2
		return 0;
	if (n == 1) //3
		return 1;
	else
	return recFibonacci(n - 1) + recFibonacci(n - 2); //4
}
int f(int n)
{
	if (n < 2) //2
		return 0; //3
	else
		return 1 + f(n / 2);//4
}
