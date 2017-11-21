#include <iostream>
using namespace std;
class Node 
{
public:
	int data;
	Node *next;

};

Node *p1, *p2, *p3;




int main()
{
p1 = new(nothrow) Node;
p2 = new(nothrow) Node;
p3 = new(nothrow) Node;


p1->data = 12;
p2->data = 34;
p3->data = 56;
p1->next = p2;
p2->next = p3;
p3->next = NULL;
cout << p1->data << "    " << p1->next->data << endl;
cout << p2->data << "    " << p2->next->data << endl;
cout << p2->next->next->data << endl;
cout << p3->data << endl;







}