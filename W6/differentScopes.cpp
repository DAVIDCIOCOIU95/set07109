#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	// Outermost declaration
	int x = 10;
	cout << "Outermost x = " << x << endl;
	{
		// Now in new scope
		int x = 20;
		cout << "\tInnerx = " << x << endl;
		{
			// Now even further in scope
			int x = 30;
			cout << "\t\tInner Inner x = " << x << endl;
			{
				// Let's stop here 
				int x = 20;
				// x = 2;
				cout << "\t\t\tInnermost x = " << x << endl;
				// Now unwind scope
			}
			cout << "\t\tInner innver x = " << x << endl;
		}
		cout << "\tInner x = " << x << endl;
	}
	cout << "Outermost x = " << x << endl;

	return 0; 
}