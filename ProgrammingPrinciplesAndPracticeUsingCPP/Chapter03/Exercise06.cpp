#include "std_lib_facilities.h"

int main ()
{

	int val1 { 0 }, val2 { 0 }, val3 { 0 };
	int smallest { 0 }, middle { 0 }, largest { 0 };

	cout << "Enter three integers: ";
	cin >> val1 >> val2 >> val3;
	
	if (!cin)
		error ("Something wrong happened to the input.");


	if (val1 <= val2 && val1 <= val3)
	{
		smallest = val1;

		if (val2 <= val3)
		{
			middle = val2;
			largest = val3;
		}
		else
		{
			middle = val3;
			largest = val2;
		}
			
	}

	if (val2 <= val1 && val2 <= val3)
	{
		smallest = val2;
		if (val1 <= val3)
		{
			middle = val1;
			largest = val3;
		}
		else
		{
			middle = val3;
			largest = val1;
		}
	}

	if (val3 <= val1 && val3 <= val2)
	{
		smallest = val3;
		if (val1 <= val2)
		{
			middle = val1;
			largest = val2;
		}
		else
		{
			middle = val2;
			largest = val1;
		}
	}

	cout << "Numerical sequence from the inputs: " << smallest << " " << middle << " " << largest << '\n';


	return 0;
}