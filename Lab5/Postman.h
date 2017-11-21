#include <iostream>
using namespace std;
enum mailbox { open, close }; //enum for open/close
const int NUM_BOX = 150; //number of mailboxes

//prototypes
void closeMailbox(int *box);
void openMailbox(int *box);
void countMailbox(int *box);



