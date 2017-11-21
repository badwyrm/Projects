#include "Rock.h"

int main()
{
	Rock bob;
	ifstream inFile("C:/Users/Andrew/Desktop/school stuff/CSCI 1107/Lab6/Rockfile.txt");
	if (!inFile) //close out if file fails
	{
		cout << "Error opening file" << endl;
		exit(1107);
	}
	
	int count[10] = { 0 };

	for (;;) //infinite loop to read file
	{
		inFile >> bob;
		count[bob.name()]++; //increment matching array element (the rock) detected in file
		cout << "Rock counted is: " << bob << endl;
		if (inFile.eof()) //only break if it reaches end of file
			break;
	}
	cout << endl;
	
	
	for (int i = 0; i < 10; i++) //print histogram
	{
		
		int n = count[i];
		string s(n, 'X'); //determines number of "x"
		cout << i << "    " << s << "    " << "(" << n << ")" << endl;
		
	}
	

}
