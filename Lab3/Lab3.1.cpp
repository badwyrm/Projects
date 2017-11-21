#include <iostream>
#include <iomanip>
using namespace std;

typedef int IntegerArray[16];
typedef char CharArray[10];
int main() {
	IntegerArray first={ 0 };
	IntegerArray arr={ 1 };
	IntegerArray last={ 2 };
	//IntegerArray prime{ 2,3,5,7,11,13,17,19,23,29,31,37,41,43, };
	//for (int i = 0; i < 16; i++)
		//cout << prime[i] << endl;
	//CharArray animal{"zebra"};
	//for (int i = 0; i < 10; i++)
	//cout << strlen(animal) << endl;
	arr[-10] = -999;
	arr[20] = 999;
	for (int i = 0; i < 15; i++)
		cout << "    " << first[i];
	cout << endl;
	for (int i = 0; i < 15; i++)
		cout << "    " << arr[i];
	cout << endl;
	for (int i = 0; i < 15; i++)
		cout << "    " << last[i];
		cout << endl;

		cout << "\narr[-10]..arr[20]:\n";
		for (int i = -10; i <= 20; i++)
			cout << arr[i] << "   ";
		cout << "\n\n\n\n\n\n\n";
		int mat[3][4] = { {11,22,33,44},{55,66,77,88},{-1,-2,-3,-4} };

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << setw(9) << mat[i][j];
			}
			cout << endl;
		}


		cout << *(mat + 0) << endl;
		cout << *(mat + 1) << endl;
		cout << *(mat + 2) << endl;
		cout << **(mat + 0) << endl;
		cout << **(mat + 1) << endl;
		cout << **(mat + 2) << endl;
		cout << *(*mat + 0) << endl;
		cout << *(*mat + 1) << endl;
		cout << *(*mat + 2) << endl;
		cout << *(*(mat+1) + 0) << endl;
		cout << *(*(mat + 1) + 1) << endl;
		cout << *(*(mat + 1) + 2) << endl;





}