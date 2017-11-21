#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
int diceroll();
void format();

int main()
{
	srand(time(NULL));				//seed
	int counter[6][6] = { 0 };		//intialize two dimensional array
	int result[13] = { 0 };

	
	int die1, die2; 
	int u = 1, x=0;

	for (int roll = 0; roll <= 36000; roll++) //generate random rolls
	{
		die1 = diceroll();
		die2 = diceroll();
		counter[die1 - 1][die2 - 1]++;
		result[die1 + die2]++;
	}

	format();

		for (int i=0; i<6; i++)				//print array
	{
		cout << u;						//formatting 
		u++;							//column of 1-6 index
		cout << setw(7);				//formatting

		for (int j=0; j < 6; j++) 
		{
			cout << counter[i][j] << setw(7);	//array print
		}
		cout << endl;
	}
	cout << endl;
	cout << "Sum" << setw(13) << "Frequency" << endl;

	for (int k = 2; k<13; k++)
	{
		cout << setw(7) << k << setw(13) << result[k] << endl;
	}
return 0;
}



int diceroll() //rolls the dice, da dice run hot!
{
 return rand() % 6 + 1;
}


void format() 
{
	cout << "      ";					//formatting block
	for (int y = 1; y <= 6; y++)		//row of 1-6 index
	{									//
		cout << setw(7) << y;			//
	}									//
	cout << endl;						//
	cout << setw(7);					//formatting block
}