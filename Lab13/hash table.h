#include<iostream>
#include<string>
#include<cstdlib>
#include<sstream>
using namespace std;

class HashTable
{
public:
	//Linked List constructor
	//Precons: None
	//Postcons: None
	HashTable()
	{
		first = NULL;
	}
	//Destructor method, destroys lists
	//Precons: None
	//Postcons: None
	~HashTable()
	{
		Node* ptr = first;
		while (ptr != 0)
		{
			first = ptr->next;
			delete ptr;
			ptr = first;
		}
	}
	//Insert function, inserts new nodes into linked lists
	//Precons: string to be inserted
	//Postcons: None
	void insert(string inItem)
	{
		Node * nPtr = new Node;
		nPtr->item = inItem;
		nPtr->next = NULL;
		if (first == NULL)
		{
			first = nPtr;
			first->next = NULL;
		}
		else
		{
			Node * nPtr2;
			nPtr2 = first;
			while (nPtr2->next != NULL)
			{
				nPtr2 = nPtr2->next;
			}
			nPtr->next = NULL;
			nPtr2->next = nPtr;
		}
	}
	//Display function, prints linked lists
	//Precons: None
	//Postcons: None
	void display()
	{
		Node * nPtr;
		nPtr = first;
		cout << "Elements are:" << endl;
		while (nPtr != NULL)
		{
			cout << nPtr->item << " // ";
			nPtr = nPtr->next;
		}
		cout << endl;
	}
private:
	class Node
	{
	public:
		string item;
		Node * next;
	};
	Node * first, next;
};


//Calculates hash value
//Precons: hashtable array, user input string
//Postcons: None
void getHash(HashTable hashtable[], string item)
{
	int hashval = 0;
	//find the ascii sum 
	for (int i = 0; i < item.length(); i++)
	{
		if (i == 3)
			break;
		hashval += (int)item.at(i);
	}
	hashval = hashval % 11;
	//insert
	hashtable[hashval].insert(item);

}
