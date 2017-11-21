#include <iostream>
#include <new>
#include <fstream>
#include <string>
#include "Queue.h"
#include "Queue.cpp"

using namespace std;

class token
{
public:
	int lineNum; //line number 
	string word; //the word
	Queue a; //the queue of word currenences


	//display function
	//Precons: ostream
	//Postcons: none
	void display(ostream &out) const 
	{
		cout << word << ", line numbers: " << a << endl;	
	}
};
//overloaded output operator
ostream &operator<<(ostream& out, const token &q) 
{
	q.display(out);
	return out;
}

//overloaded less than operator
inline bool operator <(const token& lhs, const token &rhs)
{
	return lhs.word < rhs.word;
}
