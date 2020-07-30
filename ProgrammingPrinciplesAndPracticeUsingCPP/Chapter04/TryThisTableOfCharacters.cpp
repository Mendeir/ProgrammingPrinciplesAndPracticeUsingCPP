#include "std_lib_facilities.h"

int main ()
{
	int counter { 97 };
	constexpr int number_of_alphabets { 122 };
	
	while (counter <= number_of_alphabets)
	{
		cout << char(counter) << '\t' << counter << endl;
		++counter;
	}

	return 0;
}