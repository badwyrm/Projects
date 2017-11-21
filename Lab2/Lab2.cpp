#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

const int NUM_ROWS = 15;
const int NUM_COLUMNS = 15;
typedef int TwoDimArray[NUM_ROWS][NUM_COLUMNS];
void printTable(int rows, int cols, TwoDimArray aTable);
bool check(TwoDimArray aTable, int rows, int cols);

int main() {
	int rows, cols = 0;
	TwoDimArray aTable; //initiate array


	cout << "Enter the number of rows " << endl; // collect input
	cin >> rows;
	cout << "Enter the numbers of columns " << endl;
	cin >> cols;
	cout << "Enter your elements" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cin >> aTable[i][j];
			}			
		}										//collect input


		cout << endl<< setw(7);			//formatting
		printTable(rows,cols,aTable); //function call
		bool MagicSquare = check(aTable,rows,cols); //function call and bool init


		if (MagicSquare) //function check
			cout << setw(7) << "is a magic square" << endl << endl;
		else
			cout << setw(7) << "is not a magic square" << endl << endl;

}
void printTable(int rows, int cols, TwoDimArray aTable)
//prints the user generated array
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << aTable[i][j] << setw(7);
			
		}
		cout << endl;
	}
}

bool check(TwoDimArray aTable, int rows, int cols) 
//checks if the inputted array is a magic square
{
	int required = 0;					
	for (int j = 0; j < rows; j++)		//calculate magic square sum requirement
	{
		required += aTable[0][j];
	}

	for (int i = 0; i < rows; i++)		//calculate actual sum
	{
		int sum = 0;					
		for (int j = 0; j < rows; j++)
		{
			sum += aTable[i][j];
		}
		if (sum != required)			//compare requirement to actual
		{
			return false;
		}
	}


	for (int i = 0; i < cols; i++)		//do the same thing with columns
	{
		int sum = 0;
		for (int j = 0; j < cols; j++)
		{
			sum += aTable[j][i];
		}
		if (sum != required)
		{
			return false;
		}
	}


	int Diag1Sum = 0;					//same thing with diagonals
	for (int i = 0; i < rows; i++)
	{
		Diag1Sum += aTable[i][i];
	}
	int Diag2Sum = 0;					//the other diagonal
	for (int i = 0; i < rows; i++)
	{
		Diag2Sum += aTable[rows - 1 - i][i];
	}
	if (Diag1Sum != required || Diag2Sum != required)
	{
		return false;
	}
}