/*
	Comments: The integer will start to overflow after the 46th fibonacci sequence
*/

#include <iostream>
#include <limits>

size_t getFibonacciValues ();
int calculateFibonacci (size_t sequenceNumber);
void displayFibonacci (size_t numberOfValues);
void error (std::string s);

int main ()
{
	size_t fibonacciValues = getFibonacciValues();
	displayFibonacci (fibonacciValues);

	return 0;
}

size_t getFibonacciValues ()
//Gets how many n values to display
//Pre-condition: Must return a positive integer
{
	size_t input = 0;
	while (true)
	{
		try
		{
			std::cout << "How many values of the fibonacci series you want to see? ";
			std::cin >> input;

			if (input < 0 || std::cin.fail () || std::cin.peek() != '\n')
			{
				std::cin.clear ();
				std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');
				error ("Invalid input!");
			}
			else
				return input;		
		}
		catch (const std::runtime_error &e)
		{
			std::cerr << "Runtime error: " << e.what () << '\n';
		}
	}
}

int calculateFibonacci (size_t sequenceNumber)
//Gets the nth fibonacci sequence
//Pre-condition: Must be a positive integer
{
	try
	{
		if (sequenceNumber < 0)
			error ("Number is not a positive integer");

		constexpr int firstFibonnaciNumber = 1;
		int fib0 = firstFibonnaciNumber, fib1 = firstFibonnaciNumber, temp = 0;

		if (sequenceNumber == 1 || sequenceNumber == 2)
			return 1;

		for (size_t counter = 2; counter < sequenceNumber; ++counter)
		{
			temp = fib0 + fib1;
			fib0 = fib1;
			fib1 = temp;
		}	

		return fib1;
	}
	catch (std::runtime_error &e)
	{
		std::cerr << "Error: " << e.what () << '\n';
		return -1;
	}
}

void displayFibonacci (size_t numberOfValues)
//Displays the fibonnaci series in 5 rows
//Pre-condition: Must not displayed overflowed integer
{
	try
	{
		constexpr int rowLimit = 5;
		int count = 0;
		int currFib = 0, newFib = 0;

		std::cout << "The fibonacci sequence up to " << numberOfValues << " numbers.\n";
		for (size_t counter = 1; counter <= numberOfValues; ++counter)
		{
			currFib = newFib;
			newFib = calculateFibonacci (counter);
			
			if (newFib == -1)
				error ("Something went wrong.");

			if (currFib > newFib)
			{
				std::cout << "\n\n";
				error ("Integer overflow - calculateFibonacci()");
			}

			std::cout << newFib << "\t";

			++count;

			if (count == rowLimit)
			{
				std::cout << '\n';
				count = 0;
			}

		}
	}
	catch (std::runtime_error &e)
	{
		std::cerr << "Runtime error: " << e.what () << '\n';
	}
}

void error (std::string s)
{
	throw(std::runtime_error (s));
}
