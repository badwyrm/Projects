#include<iostream>
#include<cctype>
#include<cstdlib>
#include"LStack.h"

using namespace std;

//prototypes
int operation(int op1, int op2, char operate);
int eval(char postfix[], int size);
void removeSpace(char postfix[]);

int main() 
{
	char postfix[30] = { 0 };
	cout << "Enter a postfix operation: " << endl;
	cin.getline(postfix,30);
	removeSpace(postfix);
	int val = eval(postfix, strlen(postfix));
}


//returns a value of the two popped value with the desired expression
//Precons: operator 1, operator 2, and the desired operation
//Postcons: int answer of the expression
int operation(int op1, int op2, char operate) {
	switch (operate)
	{
	case '*': //multiplication
		cout << "Token = *" << "    " << "Pop " << op1 << "    " << "Pop " << op2 << "    " << "Push " << op2 * op1 << endl;
		return op2 * op1;
	case '/': //division
		cout << "Token = /" << "    " << "Pop " << op1 << "    " << "Pop " << op2 << "    " << "Push " << op2 / op1 << endl;
		return op2 / op1;
	case '+': //addition
		cout << "Token = +" << "    " << "Pop " << op1 << "    " << "Pop " << op2 << "    " << "Push " << op2 + op1 << endl;
		return op2 + op1;
	case '-': //subtraction
		cout << "Token = -" << "    " << "Pop " << op1 << "    " << "Pop " << op2 << "    " << "Push " << op2 - op1 << endl;
		return op2 - op1;
	default: return 0;
	}
}


//determines logic for stack and traverses for single digit numbers and operators
//Precons: postfix char array, int size of the array
//Postcons: int value of the entire expression
int eval(char postfix[], int size)
{
	Stack s;
	char ch;
	int val;
	for (int i = 0; i < size; i++)
	{
		ch = postfix[i];
		if (isdigit(ch)) //digit detection
		{
			s.push(ch - '0');
			cout << "Token = " << postfix[i] << "    " << "Push " << postfix[i] << endl;
		}
		else  //operator detection
		{
			if (s.empty()) //malformed expression detection
			{
				cout << "Malformed Expression" << endl;
				exit(1107);
			}
			int op1 = s.top(); //set op1 to top of stack
			s.pop();			//pop stack
			if (s.empty()) //malformed expression detection
			{
				cout << "Malformed Expression" << endl;
				exit(1107);
			}
			int op2 = s.top(); //set op2 to top of stack
			s.pop();			//pop stack
			val = operation(op1, op2, ch); //all info gathered; call evualuation function
			s.push(val);
		}
	}
	s.pop();
	cout << "Pop " << val << endl;
	return val;
}
//removes white space the user may have entered into the char array
//Precons: postfix char array
//Postcons: none
void removeSpace(char postfix[])
{
	int i, j;
	for (i = 0; postfix[i] != 0; i++)
	{
		if (isspace(postfix[i]))
		{
			for (j = i; postfix[j] != 0; j++)
			{
				postfix[j] = postfix[j + 1];
			}
		}
	}
}