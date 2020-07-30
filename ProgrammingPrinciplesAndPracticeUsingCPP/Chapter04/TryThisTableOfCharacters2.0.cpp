#include "std_lib_facilities.h"

int main ()
{
	//display lowercase characters
	for (int counter { 97 }; counter <= 122; ++counter)
		cout << char (counter) << '\t' << counter << endl;

	//display uppercase characters
	for (int counter { 65 }; counter <= 90; ++counter)
		cout << char (counter) << '\t' << counter << endl;

	return 0;
}