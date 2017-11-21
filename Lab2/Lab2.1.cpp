#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int x;

	cout << "Please enter an odd integer to seed the magic square: ";
	cin >> x;						//collect input

	int MagicSquare[99][99] = { 0 }; //initiate the array


	int rows,
		cols;

	int a = 0;
	int b = x / 2;
	for (int i = 1; i <= x*x; i++)
	{
		MagicSquare[a][b] = i;
		rows = (a + 1) % x;
		cols = (b + 1) % x;

		if (MagicSquare[rows][cols] == 0) //reset
		{
			a = rows;
			b = cols;
		}
		else
		{
			a = (a - 1 + x) % x;
		}
	}
	for (int k = 0; k<x; k++) //print the magic square
	{
		for (int y = 0; y<x; y++)
			cout << MagicSquare[k][y] << " ";
		cout << endl;
	}
}
