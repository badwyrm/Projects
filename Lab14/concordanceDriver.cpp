#include <iostream>
#include <new>
#include <fstream>
#include <string>
#include <sstream>
#include "concordanceBST.h"

using namespace std;


int main()
{
	BST<token> b[26]; //BST of tokens
	int lineNumber = 1; //line number count
	ifstream in("C:/Users/Andrew/Desktop/School/CSCI 1107/Lab14/text.txt"); //text file to sort
	string line; //current word passed in
	char c; //line number variable
	if (!in) //check file status
	{
		cout << "error opening file";
		exit(1107);
	}

	while (in >> line) 
	{
		//capitalize all words
		for (int i = 0; i < line.length(); i++)
		{
			line[i] = toupper(line[i]);
		}

		//remove all punctuation
		for (int i = 0, len = line.size(); i < len; i++)
		{
			if (ispunct(line[i]))
			{
				line.erase(i--, 1);
				len = line.size();
			}
		}

		//count the line number
		c = in.get();
		if (c == '\n')
		{
			lineNumber++;
		}


		//start inserting into the BST
		token temp;
		temp.lineNum = lineNumber;
		temp.word = line;
		temp.a.enqueue(lineNumber);
		b[line[0] - 'A'].insert(temp);

	}

	//print the BST
	for (int i = 0; i < 26; i++)
	{
		cout << i << ") ";
		b[i].inorder(cout);
		cout << endl;
	}

}
