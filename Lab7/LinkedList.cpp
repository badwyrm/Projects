#include "LinkedList.h"
using namespace std;
//Linked List constructor
//Precons: None
//Postcons: None

LinkedList::LinkedList()
{
	first = 0;
	mySize = 0;
}
//Size method
//Precons: None
//Postcons: Size of Linked List
int LinkedList::size() const
{
	return mySize;
}
//Display function, prints linked lists
//Precons: Ostream
//Postcons: None
void LinkedList::display(ostream &) const
{
	LinkedList::NodePointer ptr;
	ptr = first;
	while (ptr != NULL)
	{
		cout << ptr->data << endl;
		ptr = ptr->next;
		
	}

}
//Overloaded cout operator
//Precons: out, Linked List
//Postcons: out
ostream &operator<<(ostream &out, const LinkedList &s) 
{
	s.display(out);
	return out;
}
//Insert function, inserts new nodes into linked lists
//Precons: dataValue to be inserted
//Postcons: None
void LinkedList::insert(ElementType dataValue)
{
		NodePointer nPtr = new(nothrow) Node(dataValue);
		
		if (index == 0)
		{
			nPtr->next = first;
			first = nPtr;
		}
		else
		{
			NodePointer predPtr = NULL;
			NodePointer currPtr = first;
			for (int i = 1; i <= index - 1; ++i)
			{
				predPtr = currPtr;
				currPtr = currPtr->next;
			}
			predPtr->next = nPtr;
			nPtr->next = currPtr;
			
		}
		mySize++;
}
	
//Erase function, deletes nodes from linked lists
//Precons: value to be deleted
//Postcons: None
void LinkedList::erase(ElementType value)
{
	NodePointer temp = NULL, prev = NULL;
	temp = first;
	while (temp != NULL)
	{
		if (temp->data == value)
		{
			if (temp == first)
			{
				first = temp->next;
				delete temp;
				mySize--;
				break;
			}
			else
			{
				prev->next = temp->next;
				delete temp;
				mySize--;
				break;
			}
		}
		else
		{
			prev = temp;
			temp = temp->next;
		}
	}
	
}
//Destructor method, destroys lists
//Precons: None
//Postcons: None
LinkedList::~LinkedList()
{
	NodePointer ptr = first;
	while (ptr != 0)
	{
		first = ptr->next;
		delete ptr;
		ptr = first;
	}

	if (first == 0)
	{
		cout << "List destroyed" << endl;
	}
	else
	{
		cout << "List not destroyed" << endl;
	}
}
//Copy function, copies entire linked lists
//Precons: A linked list to be copied
//Postcons: None
LinkedList::LinkedList(const LinkedList &origList)
{
	mySize = origList.mySize;
	if (origList.mySize == 0)
	{
		first = NULL;
	}
	else
	{
		NodePointer origPtr,lastPtr;
		origPtr = origList.first;
		lastPtr = new Node(origPtr->data);
		first = lastPtr;
		if(origPtr->next != NULL)
		{
			origPtr = origPtr->next;
			lastPtr->next = new Node(origPtr->data);
			lastPtr = lastPtr->next;
			
		}
	}
}
//Overloaded assignment operator
//Precons: a linked list
//Postcons: None
LinkedList &LinkedList::operator=(const LinkedList &origList) 
{

	if (this != &origList) 
	{
		mySize = origList.mySize;
		if (origList.mySize == 0)
		{
			first = NULL;
		}
		else 
		{
			mySize = origList.mySize;
			this->~LinkedList();
			NodePointer origPtr, lastPtr;
			origPtr = origList.first;
			lastPtr = new Node(origPtr->data);
			first = lastPtr;
			NodePointer temp;
			while (origPtr != NULL) //cycle through origList
			{
				temp = new Node(origPtr->data); //copy data in current node of origList
				lastPtr->next = temp;  //add temp to end of this list
				lastPtr = lastPtr->next; //advance lastPtr to end of this list
				origPtr = origPtr->next; //go to next node in origList
			}
		}
	}
	return *this;
}