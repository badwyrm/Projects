/*--- Queue.h -------------------------------------------------------------
  This header file contains the declaration of class Queue.
  
  Basic operations:
     Constructor: Constructs an empty queue
     empty:       Checks if a queue is empty
     enqueue:     Modifies a queue by adding a value at the back
     front:       Accesses the front queue value; leaves queue unchanged
     dequeue:     Modifies a queue by removing the value at the front
     display:     Displays the queue elements from front to back
  Class Invariant:
      1. The queue elements (if any) are stored in consecutive positions
         in myArray, beginning at position myFront.
      2. 0 <= myFront, myBack < QUEUE_CAPACITY
      3. Queue's size < QUEUE_CAPACITY
  
  Written by:   Larry R. Nyhoff
   
  Written for:  Lab Manual for ADTs, Data Structures, and Problem
                Solving with C++, 2E

                               Lab #6.1
 --------------------------------------------------------------------------*/


#ifndef QUEUE
#define QUEUE
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
const int QUEUE_CAPACITY = 128;
typedef int QueueElement;

class Queue
{
 public:
  /***** Function Members *****/
  /***** Constructor *****/
  Queue();
  /*-----------------------------------------------------------------------
    Construct a Queue object.

    Precondition:  None.
    Postcondition: An empty Queue object has been constructed; myFront 
        and myBack are initialized to -1 and myArray is an array with
        QUEUE_CAPACITY elements of type QueueElement.
   ----------------------------------------------------------------------*/
   /***** Copy *****/
  Queue(const Queue & original);

   /***** Destructor *****/
  ~Queue();
  /*------------------------------------------------------------------------
  Class destructor

  Precondition:  None
  Postcondition: The linked list in the stack has been deallocated.
  ------------------------------------------------------------------------*/

  /***** Assignment *****/
  const Queue & operator= (const Queue & rightHandSide);
  /*------------------------------------------------------------------------
  Assignment Operator
  Precondition:  rightHandSide is the stack to be assigned and is
  received as a const reference parameter.
  Postcondition: The current stack becomes a copy of rightHandSide
  and a const reference to it is returned.
  ------------------------------------------------------------------------*/

  bool empty() const;
  /*-----------------------------------------------------------------------
    Check if queue is empty.

    Precondition: None.
    Postcondition: True is returned if the queue is empty and false is
        returned otherwise.
   ----------------------------------------------------------------------*/

  void enqueue(const QueueElement & value);
  /*-----------------------------------------------------------------------
    Add a value to a queue.

    Precondition:  value is to be added to this queue.
    Postcondition: value is added to back of queue provided there is space;
        otherwise, a queue-full message is displayed and execution is
        terminated.
   -----------------------------------------------------------------------*/

  void display(ostream & out) const;
  /*-----------------------------------------------------------------------
    Output the values stored in the queue.

    Precondition:  ostream out is open.
    Postcondition: Queue's contents, from front to back, have been output 
        to out.
   -----------------------------------------------------------------------*/

  QueueElement front() const;
  /*-----------------------------------------------------------------------
    Retrieve value at front of queue (if any).

    Precondition:  Queue is nonempty.
    Postcondition: Value at front of queue is returned, unless queue is
        empty; in that case, an error message is displayed and a "garbage
        value" is returned.
   ----------------------------------------------------------------------*/

  void dequeue();
  /*-----------------------------------------------------------------------
    Remove value at front of queue (if any).

    Precondition:  Queue is nonempty.
    Postcondition: Value at front of queue has been removed, unless queue
        is empty; in that case, an error message is displayed and 
        execution is terminated.
   ----------------------------------------------------------------------*/ 

 private:
  /***** Data Members *****/
   int myFront,
       myBack;
   int myCapacity;
   QueueElement *myArray = new QueueElement[myCapacity];
}; // end of class declaration

//overloaded output operator
ostream &operator<<(ostream &out, const Queue &q);

#endif
