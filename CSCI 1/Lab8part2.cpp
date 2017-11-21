//****************************************************************************
// Programmer: Andrew Tran
//
// Description: To display various statistics using a simulation to calculate 
//				Mighty Casey's batting information over a large amount of times
//*****************************************************************************
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	int count = 1;
	double out = 0, walk = 0, single = 0, two = 0, three = 0, homeRun = 0;
	srand(time(NULL));

	do {
		
		int number = rand() % 100;

		if (number <= 35)
			out++;
		else if (number <= 51)
			walk++;
		else if (number <= 71)
			single++;
		else if (number <= 86)
			two++;
		else if (number <= 95)
			three++;
		else if (number <= 100)
			homeRun++;

		count++;

	} while (count <= 1000);

	double average = (single + two + three + homeRun) / (count - walk);
	double slugging = (single + (two * 2) + (three * 3) + (homeRun * 4)) / (count - walk);
	cout << "Outs: "<< out << "\nWalks: " << walk << "\nSingles: " << single << "\nDoubles: " << two << "\nTriples: " << three << "\nHome Runs: " << homeRun << endl;
	cout << "\nMighty Casey's batting average is "<< average << endl;
	cout << "Mighty Casey's slugging percentage is " << slugging << endl;
	return 0;
}
