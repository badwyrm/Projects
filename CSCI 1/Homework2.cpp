#include <iostream>
#include <fstream>

using namespace std;

//prototypes
void movement(int, int& rows, int& columns);
int compassRight(int, int);
int compassLeft(int, int);
void print(int[8][60]);

int main() {
	int turnCommand, spacesMoved, rows=0, columns=0, array[8][60], direction=1, pen = 0;
	char command;
	ifstream infile;
	infile.open("turtle.txt");

	if (!infile)
	{
		cout << "Error opening file." << endl;
		cout << "Terminating Program..." << endl;
	}

	infile >> command;

	/* 
	COMMAND LIST
	--------------------------
	U = pen up
	D = pen down
	R = right turn
	L = left turn
	F(x) = move forward x spaces
	P = print array
	Q = end
	*/

	while (command != 'Q')
	{
		
		switch (command)
		{
		case 'U':
			pen = 0;
			break;

		case 'D':
			pen = 1;
			break;

		case 'R':
			turnCommand = 1;
			direction = compassRight(direction, turnCommand);
			break;

		case 'L':
			turnCommand = 2;
			direction = compassLeft(direction, turnCommand);
			break;

		case 'F':
			infile >> spacesMoved;
			for (int i = 0; i < spacesMoved; i++)
			{
				movement(direction, rows, columns);
				if (pen == 1) 
				{
					array[rows][columns] = '*';
				}			
			}
			break;

		case 'P':
			print(array);
			break;
		}
		infile >> command;
	}
}


void print(int array[8][60])
{
	for (int i = 0; i < 8; i++)
	{
		cout << endl;
		for (int j = 0; j < 60; j++)
		{
			switch(array[i][j])
			{
			case '*':		
					cout << "*";
					break;
			default:
					cout << " ";
					break;
			}
		}
	}
	cout << endl;
}

int compassRight(int direction, int turnCommand)
{
	if (turnCommand == 1 && direction == 3)
		direction = 0;
	else if (turnCommand == 1 && direction != 3)
		direction++;
	return direction;
}

int compassLeft(int direction, int turnCommand)
{
	if (turnCommand == 2 && direction == 0)
		direction = 3;
	else if (turnCommand == 2 && direction != 0)
		direction--;
	return direction;
}

void movement(int direction, int& rows, int&columns)
{
	switch (direction)
	{
	case 0:
		rows--;
		break;
	case 1:
		columns++;
		break;
	case 2:
		rows++;
		break;
	case 3:
		columns--;
		break;
	}
}
