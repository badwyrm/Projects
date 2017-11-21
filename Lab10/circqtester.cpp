#include<string>
#include<iostream>
#include<fstream>
#include "Queue.h"
using namespace std;

int main(){

		Queue q1;

		q1.enqueue(10);
		q1.enqueue(20);
		q1.enqueue(30);
          
		q1.display(cout);
		cout << q1 << endl;
		{
			Queue q;
			q.enqueue(10);
			q.enqueue(20);
			q.enqueue(30);
			cout << "in { } for queue" << q << endl;
			cout << "Testing destructor " << endl;

		}
		Queue q2(q1);
		cout << "Testing copy constructor " << endl;

		cout << q2 << endl;

		Queue q3;

		q3 = q2;
		cout << "Testing assignment operator." << endl;

		cout << q3 << endl;

		cout <<"Testing front method: " <<  q3.front() << endl;

		while(!q3.empty()){
			q3.dequeue();
			cout << q3 << endl;
		}// end while

	      

	return 0;
}// end main