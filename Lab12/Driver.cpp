#include <iostream>
#include "QueueTemplate2.h"
using namespace std;

int main() {
	double a;
	Student s;
	CircularQ<double> qdub; //qdub1 and qdub2 joined together
	CircularQ<double> qdub1; //contains doubles 0.0,1.1,2.2,...,9.9
	CircularQ<double> qdub2; //contains 5 doubles
	CircularQ<CircularQ<double>> qq; //a queue of queues qdub1, qdub2, and qdub
	CircularQ<string> qstr;
	CircularQ<Student> qstu;
	CircularQ<StudentPointer> qptr;
	char answer;
	string name;
	int id;
	StudentPointer stuPtr = 0;
	cout << "Beginning Part 2" << endl;
	cout << "Feature 1 - qdub1 and qdub2" << endl << endl;
	for (int i = 0; i < 10; i++)
	{
		a = i*1.1;
		qdub1.enqueue(a);
	}
	cout << "qdub1: " << qdub1 << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << "Input a number for qdub2: " << endl;
		cin >> a;
		qdub2.enqueue(a);
	}
	cout << "qdub2: " << qdub2 << endl << endl;



	cout << "Feature 2 - joining qdub1 and qdub2" << endl << endl;
	//begin joining qdub1 and qdub2
	qdub = join(qdub1, qdub2);











	cout << "Feature 3 - Student objects" << endl << endl;;

	for (;;)
	{
		cout << "Enter the name of your student " << endl;
		cin >> name;
		s.getName(name);
		cout << "Enter the ID of your student " << endl;
		cin >> id;
		s.getID(id);
		qstu.enqueue(s);
		cout << "qstu: " << qstu << endl << endl;
		cout << "Do you want to enter another Student? n to quit" << endl;
		cin >> answer;
		if (answer == 'n')
		{
			break;
		}
	}


	for (;;)
	{
		stuPtr = new Student();
		cout << "Feature 4 - Student pointers" << endl << endl;

		cout << "Enter the name of your student " << endl;
		cin >> name;

		stuPtr->getName(name);

		cout << "Enter the ID of your student " << endl;
		cin >> id;
		stuPtr->getID(id);
		qptr.enqueue(stuPtr);
		cout << "qptr: " << qptr << endl << endl;


		answer = 0;
		cout << "Do you want to enter another Student? n to quit" << endl;
		cin >> answer;
		if (answer == 'n')
		{
			break;
		}
	}
	delete stuPtr;

	cout << "Feature 5 - Queues of queues" << endl << endl;

	//begin queue of queue of qdub, qdub1, and qdub2

	//qq.enqueue(qdub2);
	//qq.enqueue(qdub1);
	qq.enqueue(qdub);

	cout << "qq: " << qq << endl;

}