#include <iostream>
using namespace std;
int indent = -2;
int GCD(int a, int b);

int main()
{
	int a=0, b=0;
	cout << "Enter the first number for the GCD: " << endl;
	cin >> a;
	cout << "Enter the second number for the GCD: " << endl;
	cin >> b;
	cout << "The GCD of the two numbers is " << GCD(a, b) << endl;
}

int GCD(int a, int b)
{
	indent += 2;
	for (int i = 0; i < indent; i++)
	{
		cout << " ";
	}
	cout << "-> entering f(" << a << ", " << b << ")" << endl;
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (b == 0)
	{
		cout << "<- f(" << a << ", " << b << ") returns " << a << endl;
		indent -= 2;
		return a;
	}
	else
	{
		cout << "<- f(" << a << ", " << b << ") returns " << GCD(b, a % b) << endl;
		indent -= 2;
		return GCD(b, a % b);
	}
}