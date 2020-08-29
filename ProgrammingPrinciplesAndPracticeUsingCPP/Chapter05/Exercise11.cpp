#include <iostream>

int fibonnaci (int n);

int main ()
{
	std::cout << fibonnaci (6);
	

	return 0;
}

int fibonnaci (int n)
{
	if (n <= 1)
		return n;

	return (fibonnaci (n - 1) + fibonnaci (n - 2));
}