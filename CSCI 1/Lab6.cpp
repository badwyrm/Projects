#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	char color;
	char answer;
	
	do{
		cout << "Enter the first letter of the color of the cylinder: ";
		cin >> color;

		switch (color) {
		case 'o': cout << "Ammonia";
			break;
		case 'O': cout << "Ammonia";
			break;
		case 'y': cout << "Hydrogen";
			break;
		case 'Y': cout << "Hydrogen";
			break;
		case 'b': cout << "Carbon Monoxide";
			break;
		case 'B': cout << "Carbon Monoxide";
			break;
		case 'g': cout << "Oxygen";
			break;
		case 'G': cout << "Oxygen";
			break;
		default: cout << "Contents Unknown";
			break;
		}
		cout << "\nPress e or E to exit the program, otherwise press any key: ";
		cin >> answer;
			if (answer == 'e' || answer == 'E') {
				break;
			}
		
	} while (1 == 1);

}
