/*--- Queue.cpp -----------------------------------------------------------
  This implementation contains definitions of the function members for
  the class Queue.
  
  Written by:   Larry R. Nyhoff
   
  Written for:  Lab Manual for ADTs, Data Structures, and Problem
                Solving with C++, 2E

                               Lab #6.1
--------------------------------------------------------------------------*/

#include<string>
#include<iostream>
#include<fstream>
using namespace std;



//default constructor
Queue::Queue()
{
	myCapacity = 25;
	myArray = new(nothrow)QueueElement[myCapacity];
	if (myArray != 0)
	{
		myFront = 0;
		myBack = 0;
	}
	else
	{
		cout << "Insufficient Space" << endl;
		exit(1107);
	}
}
//copy constructor
//Precons: original Queue
//Postcons: lnewly copied myArray
Queue::Queue(const Queue & original)
: myCapacity(original.myCapacity), myFront(original.myFront),myBack(original.myBack) 
{
	myArray = new(nothrow) QueueElement[myCapacity];
	if (myArray != 0)
	{
		for (int i = myFront; i != myBack; i = (i + 1) % myCapacity)
			myArray[i] = original.myArray[i];
	}
	else
	{
		cout << "Insufficient Memory" << endl;
		exit(1107);
	}


}
//destructor
Queue::~Queue()
{
	delete[] myArray;
}

const Queue & Queue::operator= (const Queue & rightHandSide)
{
	if (this != &rightHandSide)
	{
		delete[] myArray;
		myCapacity = rightHandSide.myCapacity;
		myArray = new QueueElement[myCapacity];
		if (myArray == 0)
		{
			cout << "Insufficient Space" << endl;
			exit(1107);
		}
	}
	myFront = rightHandSide.myFront;
	myBack = rightHandSide.myBack;
	for (int i = myFront; i != myBack; i = (i + 1) % myCapacity)
	{
		myArray[i] = rightHandSide.myArray[i];
	}
	return *this;
}

//Empty function, returns if the queue is empty
//Precons: none
//Postcons: bool
bool Queue::empty() const
{ 
   return (myFront == myBack); 
}

//Enqueue function, adds a value to the queue
//Precons: a value to enqueue
//Postcons: none
void Queue::enqueue(const QueueElement & value)
{
   int newBack = (myBack + 1) % QUEUE_CAPACITY;
   if (newBack != myFront)     // queue isn't full
   { 
      myArray[myBack] = value;
      myBack = newBack;
   }
   else
   {
      cerr << "*** Queue full -- can't add new value ***\n"
              "Must increase value of QUEUE_CAPACITY in Queue.h\n";
      exit(1);
   }
}
//Display function, displays current queue
//Precons: outstream
//Postcons: none
void Queue::display(ostream & out) const
{
   for (int i = myFront; i != myBack; i = (i + 1)%QUEUE_CAPACITY) 
      out << myArray[i] << "  ";
   cout << endl;
}
//overloaded output operator
//Precons: outstream, Queue to output
//Postcons: outstream
ostream &operator<<(ostream &out, const Queue &q)
{
	q.display(out);
	return out;
}
//front function, returns value at the front of the queue
//Precons: none
//Postcons: front value
QueueElement Queue::front() const
{
   if ( !empty() ) 
      return (myArray[myFront]);
   else
   {
      cerr << "*** Queue is empty -- returning garbage value ***\n";
      QueueElement garbage = 0;
      return garbage;
   }
}

//dequeue function, moves myFront ptr forward
//Precons: none
//Postcons: none
void Queue::dequeue()
{
   if ( !empty() )
      myFront = (myFront + 1) % QUEUE_CAPACITY;
   else
   {
      cerr << "*** Queue is empty -- "
              "can't remove a value ***\n";
      exit(1);
   }
}
