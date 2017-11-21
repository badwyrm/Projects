#include <iostream>
#include "Postman.h"
using namespace std;


//Closes all mailboxes
//Precons: Box array
//Postcons: None
void closeMailbox(int *box)
{
	int i;
	for (i = 1; i <= NUM_BOX; i++) //loop to close all boxes
	{
		box[i] = close;
	}
}

//Opens every even number mailbox first
//Then recurs with every 3rd, 4th, 5th and so on.
//Precons: Box array
//Postcons: None
void openMailbox(int *box)
{
	int e;
	for (e = 2; e <= NUM_BOX; (e += 2)) //open every other box starting with two
	{
		box[e] = open;
	}


	for (int k = 3; k <= NUM_BOX; k++)
	{
		for (int q = k; q<NUM_BOX; q += k)
		{
			if (box[q] == close)
				box[q] = open;
			else     // box must be open 
				box[q] = close;
		}

	}
}

//Counts the number of total closed mailboxes
//Precons: Box array
//Postcons: None
void countMailbox(int *box)
{
	int j;
	for (j = 1; j <= NUM_BOX; j++)
	{
		if (box[j] == close)
		{
			cout << "Mailbox number " << j << " is closed" << endl;
		}
	}
}




