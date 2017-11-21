#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;
int main() {
	int number_of_lines = 0;
	ifstream myfile("GettysburghAddress.txt");
	int letter = 0;
	int uppercase = 0;
	int punct = 0;
	int whitespace = 0;
	char singleCharacter;

	myfile.get(singleCharacter);

	while (!myfile.eof())
	{
		if (isupper(singleCharacter))
			uppercase++;
		else if (isalpha(singleCharacter))
			letter++;
		else if (ispunct(singleCharacter))
			punct++;
		else if (isspace(singleCharacter))
			whitespace++;

		myfile.get(singleCharacter);
	}
	cout << "Letters: " << letter << endl;
	cout << "Uppercase: " << uppercase << endl;
	cout << "Punctuation: " << punct << endl;
	cout << "Whitespace: " << whitespace << endl;
}
