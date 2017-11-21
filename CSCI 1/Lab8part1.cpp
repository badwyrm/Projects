//****************************************************************************
// Programmer: Andrew Tran
//
// Description: To produce a bar chart to reflect the population of a town at 20 year
//				intervals
//*****************************************************************************
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream inputFile;
	int population;
	int year = 1900;
	int stars;
	inputFile.open("People.txt");


	cout << "PRAIRIEVILLE POPULATION GROWTH" << endl;
	cout << "(each * represents 1,000 people)" << endl << endl;

	while (year <= 2000)
	{
		cout << year << ' ';
		inputFile >> population;


		for (stars = 1; stars < population; stars += 1000)
		{
			cout << '*';
		}
		cout << endl;
		year += 20;
	}
}