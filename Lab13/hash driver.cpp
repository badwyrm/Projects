#include <iostream>
#include "hash table.h"
using namespace std;

int main()
{
	//array of linkedlist to implement hashtable
	HashTable hashtable[11];
	//item to insert
	string item;
	//read input
	string a;
	int hashval = 0;
	while (1) 
	{
		cout << "Insert a string to be inserted into the hash table (000 to break): " << endl;
		getline(cin, a, '\n');
		if (a == "000") //check for end of input
			break;
		stringstream buffer;
		buffer << a;
		//split the text as separate strings
		while (getline(buffer, item, ' '))
		{
			getHash(hashtable, item);
		}
	}
	//display the hashtable contents
	for (int i = 0; i < 11; i++)
	{
		cout << "Hash Index " << i << endl << endl;
		hashtable[i].display();
		cout << "==============================" << endl;
	}
	return 0;
}