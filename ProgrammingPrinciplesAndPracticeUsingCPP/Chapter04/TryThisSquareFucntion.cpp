#include "std_lib_facilities.h"

int square (int x)
{
	const int number_of_counts { x };

	for (int counter = 1; counter < number_of_counts; ++counter)
		x += number_of_counts;

	return x;
}

void print_square (int counter)
{
	cout << counter << '\t' << square (counter) << endl;
}


int main ()
{

	for (int counter = 1; counter <= 100; ++counter) 
		print_square (counter);

	return 0;
}