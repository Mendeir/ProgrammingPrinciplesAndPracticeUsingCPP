#include <iostream>

void error (std::string s)
{
	throw std::runtime_error (s);
}

int main ()
try
{
	error ("You cannot divide by 0");
	return 0;
}
catch (std::runtime_error &e)
{
	std::cerr << "Runtime error: " << e.what () << '\n';
	return 1;
}		