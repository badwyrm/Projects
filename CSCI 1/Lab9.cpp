#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream myfile;
	myfile.open("pb_2014.txt");

	int countone;
	int counttwo;
	double number;

	ofstream writingfile;
	writingfile.open("powerball.txt");

	for (countone = 0; countone < 100; countone++)
	{
		
		for (counttwo = 0; counttwo < 6; counttwo++)
		{
			myfile.ignore(10, ' ');
			myfile >> number;
			writingfile << setw(2) << setfill('0') << number << ' ';
		}
		writingfile << endl;	
		myfile.ignore(10);

	}
	myfile.close();
	writingfile.close();
	cout << "Writing to powerball.txt ---- Done." << endl;
	return 0;
}
