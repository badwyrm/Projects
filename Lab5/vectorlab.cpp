/*--- vectorlab.cpp -------------------------------------------------------
  A study of STL's vector container
  
  Written by:   Larry R. Nyhoff
   
  Written for:  Lab Manual for ADTs, Data Structures, and Problem
                Solving with C++, 2E

                            Lab #7.1
                                                          
  Add your name here and other info requested by your instructor.
  
 --------------------------------------------------------------------------*/


#include <iostream>
#include <vector>
using namespace std;

template <typename T>
ostream & operator<<(ostream & out, const vector<T> & v)
/*-------------------------------------------------------------------------
  Overloaded output operator for vector<T>s.

  Precondition:  ostream out is open.
  Postcondition: Elements of v have been output to out and out is returned.
 --------------------------------------------------------------------------*/

{
   for (int i = 0; i < v.size(); i++)
      out << v[i] << "  ";
   return out;
}

int main()
{
	// Declare 6 vectors v1, v2, v3, v4, v5, v6 to illustrate the
	// various types of declarations (and constructors)
	vector<int> v1;
	vector<int> v2(2);
	int numInts;
	cout << "Enter capacity of v3: ";
	cin >> numInts;
	vector<int> v3(numInts);
	vector<int> v4(3, 99);
	// The preceding declaration should work, but it may not in some
	// versions of some compilers. The following is a work-around:
	// vector<int> v4(3);
	// for (int i = 0; i < 3; i++)  v4[i] = 99;
	//--- End of work-around

	int a[] = { 1, 4, 9, 16, 25 };
	vector<int> v5(a, a + 5);
	vector<int> v6;

	//--- 1 --- Add:
	// Statements to display the capacity and size of each vector<int>
	// and whether it is empty
	cout << "1 lab" << endl;
	cout << v1.capacity() << ' ' << v1.size() << ' ' << v1.empty() << endl;
	cout << v2.capacity() << ' ' << v2.size() << ' ' << v2.empty() << endl;
	cout << v3.capacity() << ' ' << v3.size() << ' ' << v3.empty() << endl;
	cout << v4.capacity() << ' ' << v4.size() << ' ' << v4.empty() << endl;
	cout << v5.capacity() << ' ' << v5.size() << ' ' << v5.empty() << endl;
	cout << v6.capacity() << ' ' << v6.size() << ' ' << v6.empty() << endl;


	//--- 2 --- Add:
	// Statements to display the maximum capacity of a vector<int>
	cout << "2 lab" << endl;

	cout << v1.max_size() << endl;

	//--- 3 --- Add:
	// Statements to see the effect of the reserve() member function
	cout << "3 lab" << endl;
	v4.reserve(7);
	cout << v4.capacity() << ' ' << v4.size() << ' ' << v4.empty() << endl;

	//--- 4 --- Add:
	// Output statements of the form   cout << vector-variable << endl;
	// to display the contents of each vector
	cout << "4 lab" << endl;
	cout << v1 << endl;
	cout << v2 << endl;
	cout << v3 << endl;
	cout << v4 << endl;
	cout << v5 << endl;
	cout << v6 << endl;


	//--- 5 --- Add:
	// Statements to append 11 to v2 and then output v2's size and contents
	//               append 22 to v2 and then output v2's size and contents
	//               append 33 to v2 and then output v2's size and contents
	//               remove the last element of v2 and then output v2's size
	//                  and contents
	cout << "5 lab" << endl;

	v2.push_back(11);
	cout << v2.size() << ' ' << v2 << endl;
	v2.push_back(22);
	cout << v2.size() << ' ' << v2 << endl;
	v2.push_back(33);
	cout << v2.size() << ' ' << v2 << endl;
	v2.pop_back();
	cout << v2.size() << ' ' << v2 << endl;

	//--- 6 --- Statements to investigate how capacities grow
	// Add statements to append 111 to v1 and then output v1's capacity, size,
	// and contents
	cout << "6 lab" << endl;

	v1.push_back(111);
	cout << v1.capacity() << ' ' << v1.size() << ' ' << v1 << endl;


	//--- 7 --- Statements to investigate how capacities grow
	// Add statements to append 222, 333, 444, and 555 to v1 and output 
	// v1's capacity, size, and contents after each value is appended
	cout << "7 lab" << endl;

	v1.push_back(222);
	cout << v1.capacity() << ' ' << v1.size() << ' ' << v1 << endl;
	v1.push_back(333);
	cout << v1.capacity() << ' ' << v1.size() << ' ' << v1 << endl;
	v1.push_back(444);
	cout << v1.capacity() << ' ' << v1.size() << ' ' << v1 << endl;
	v1.push_back(555);
	cout << v1.capacity() << ' ' << v1.size() << ' ' << v1 << endl;



	//--- 8 --- Statements to investigate how capacities grow
	// Remove the comment delimiters from the following:
	cout << "8 lab" << endl;

	int oldCapacity = v1.capacity();
	for (int i = v1.size() + 1; i <= 2500; i++)
	{
		v1.push_back(999);
		if (v1.capacity() == v1.size())
			cout << "\n*** v1 is full with " << v1.size() << " elements\n";
		if (v1.capacity() > oldCapacity)
		{
			cout << "Adding an element increases capacity from "
				<< oldCapacity << " to " << v1.capacity() << endl;
			oldCapacity = v1.capacity();
		}
	}


	//--- 9 --- Statements to see if element type affects how capacities grow
	// Add:
	//    A declaration of an empty vector<double> v0; 
	//    A loop like the preceding but with v1 replaced by v0 
	//
	// Then change double to char and run it again.
	cout << "9 lab" << endl;

	vector<char> v0;
	for (int i = v0.size() + 1; i <= 2500; i++)
	{
		v0.push_back(999);
		if (v0.capacity() == v0.size())
			cout << "\n*** v0 is full with " << v0.size() << " elements\n";
		if (v0.capacity() > oldCapacity)
		{
			cout << "Adding an element increases capacity from "
				<< oldCapacity << " to " << v0.capacity() << endl;
			oldCapacity = v0.capacity();
		}
	}

	//--- 10 --- Statements to see how initial capacity affects 
	//           how capacities grow
	// Uncomment the following line:
	cout << "10 lab" << endl;

	cout << "Initial capacity of v4 is " << v4.capacity() << endl;

	// Add a loop like that in 9 but output changes in v4's capacity

	for (int i = v4.size() + 1; i <= 2500; i++)
	{
		v4.push_back(999);
		if (v4.capacity() == v4.size())
			cout << "\n*** v4 is full with " << v4.size() << " elements\n";
		if (v4.capacity() > oldCapacity)
		{
			cout << "Adding an element increases capacity from "
				<< oldCapacity << " to " << v4.capacity() << endl;
			oldCapacity = v4.capacity();
		}
	}


	//--- 11 --- Statements to access the ends of a vector

	// Uncomment the following line:
	cout << "11 lab" << endl;

	cout << "Original contents of v5: " << v5 << endl;

	// Add statements to:
	//    Output the first and last elements of v5
	//    Change the first element to 77 and the last element to 88
	//    Output the contents of v5

	v5.front() = 77;
	v5.back() = 88;
	cout << "Altered contents of v5: " << v5 << endl;

	//--- 12 --- Statements to demonstrate correct and incorrect
	//           use of the subscript operator
	// Add statements that try using the subscript operator to:
	//            change the value in location 1 of v2 to 2222
	//            append the value 3333 to v2
	//            append a value to empty vector v6
	cout << "12 lab" << endl;
	v2[1] = 2222;
	cout << v2 << endl;
	/*v2[v2.size()] = 3333;
	for (int i = 0; i <= v2.size(); i++)
		cout << v2[i] << "  ";
	cout << endl;*/
	cout << v2.capacity() << ' ' << v2.size() << ' ' << v2.empty() << endl;



	//--- 13 --- Add statements that:
	//            assign v5 to v3
	//            check if they are equal
	//            check if v5 is less than v2
	//            swap contents of v5 and v2
	//            check if v5 is less than v2
	cout << "13 lab" << endl;
	v5 = v3;
	v5 == v3;
	if (v5 == v3)
	{
		cout << "true" << endl;
	}
	else
		cout << "false" << endl;
	if (v5<v2)
	{
		cout << "true" << endl;
	}
	else
		cout << "false" << endl;
	v2 == v5;
	if (v5<v2)
	{
		cout << "true" << endl;
	}
	else
		cout << "false" << endl;

}