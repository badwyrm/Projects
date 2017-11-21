/* pointers.cpp provides a laboratory for experimenting with
 * addresses and pointers.
 *
 *	Programmer: Andrew Tran
 *************************************************************************/

#include <iostream>
using namespace std;

int main()
{




  int int1 = 11,
      int2 = 22,
      int3 = 33;
  double dub1 = 1.23,
         dub2 = 7.89,
         dub3 = 1.23;

  int *intPtr1;
  int *intPtr2 = &int2;
  double *dubPtr1;
  double *dubPtr2 = &dub2;
  


  cout << "int1, int2, int3:" << endl
       << int1 << "  " << int2 << "  " << int3 << "\n\n";
  cout << "dub1, dub2, dub3:" << endl
       << dub1 << "  " << dub2 << "  " << dub3 << "\n\n";



  cout << intPtr2 << endl;
  cout << dubPtr2 << endl << endl;




  
}