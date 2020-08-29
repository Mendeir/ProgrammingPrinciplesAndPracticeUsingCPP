#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

int numberOfValuesInput ();
void getUserInputs (std::vector<int> &userInputs);
void addFirstNVector (const std::vector<int> givenVector, size_t n);
void error (std::string s);
void badInputError (const std::string s);

int main ()
{
	try
	{
		size_t numberOfValues = numberOfValuesInput ();
		std::vector<int> userIntInputs;

		getUserInputs (userIntInputs);
		addFirstNVector (userIntInputs, numberOfValues);
	}
	catch (std::runtime_error &s)
	{
		std::cerr << "Runtime Error: " << s.what () << '\n';
	}
	return 0;
}

int numberOfValuesInput ()
//Get input from user in which will be used to determine the first n numbers to add to the vector
//Post-condition: The function must return an integer only.
//Pre-condition: The function must return a posiitive integer
{
	while (true)
	{
		std::cout << "Enter the number of first values you want to add: ";

		size_t numberOfValues = 0;
		std::cin >> numberOfValues;

		if (std::cin.fail () || std::cin.get () != '\n' || numberOfValues < 0)
		{
			std::cin.clear ();
			std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');
			badInputError ("Not an integer.");
			std::cout << '\n';
		}
		else
			return numberOfValues;
	}
}

void getUserInputs (std::vector<int> &userInputs)
//Get integer inputs from the user and put those inputs into a integer vector
//Post-condition: The vector must contain only integers.
//Known unhandled errors: Integer overflow when given the maximum limit.
{
	float inputs = 0;

	std::cout << "Enter some integers (enter '|' to stop): ";

	while (std::cin >> inputs)
	{
		if (inputs == '|')
			return;

		if (std::cin.fail () || ceil (inputs) - inputs)
		{
			std::cin.clear ();
			std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');
			badInputError ("An input has been detected to be non-integer type.");;
			std::cout << '\n';
		}
		else
			userInputs.push_back (inputs);
	}
}

void addFirstNVector (const std::vector<int> givenVector, size_t n)
//Adds and display the first n numbers and its sum 
//Pre-condition: Given vector must be larger or equal to n
//Post-condition: Sum must not overflow
{
	if (givenVector.size () < n)
		error ("Numbers from the vector is not enough to add the given n numbers.");

	int sum = 0;
	int max = givenVector [0];


	std::cout << "The sum of first " << n << " numbers ( ";
	for (size_t counter = 0; counter < n; ++counter)
	{
		std::cout << givenVector [counter];
		if (counter != n - 1)
			std::cout << ", ";

		sum += givenVector [counter];
		if (max < givenVector [counter])
			max = givenVector [counter];
	}

	if (max > sum)
		error ("Integer overflow");

	std::cout << " ) is: " << sum << '\n';

}

void error (std::string s)
{
	throw(std::runtime_error (s));
}

void badInputError (std::string s)
{
	std::cerr << "Input error: " << s << " Please try again.\n";
}