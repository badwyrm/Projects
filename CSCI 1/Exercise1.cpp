#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	srand(time(NULL));
	double trials = 1000;
	int position = 0;
	int collisions;
	int collisionLimit = 10;
	int oldDirection;
	double escaped = 0;

	for (int count = 1; count <= trials; count++)
	{
		position = oldDirection = collisions = 0;
		while (position < 5 && position >= 0 && collisions < collisionLimit)
		{
			int direction = rand() % 4;
			if (direction != oldDirection)
				collisions++;

			oldDirection = direction;

			if (direction == 1)
				position++;
			else if (direction == 2)
				position--;
		}
		if (position >= 5)
			escaped++;
	}
	cout << escaped << " particles out of " << trials << " escaped. " << endl;
	cout << "That equates to " << 100 * escaped / trials << "% of the particles escaped." << endl;
	
}