#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <limits>
#include <sstream>

std::vector<int> genFourRandomNum ();
std::vector<int> getUserGuess ();
int calculateBull (std::vector<int> userGuess, std::vector<int> randomNumbers);
int calculateCow (std::vector<int> userGuess, std::vector<int> randomNumbers);
bool playAgain ();
void displayInterface ();
void error (std::string s);
void game ();

int main ()
{
	game ();
}

void game ()
//Handles the game flow and rules
{
	std::cout << "Bulls and Cows Game\n";
	std::cout << "\nIm thinking of a four unique digits numbers can you guess the numbers that i'm thinking?\n";
	std::cout << "\nHint: If you guessed the number and it is in the correct place, I'll add a point to the bull,\n"
		<< "if you guess the number but it is in the wrong place, I'll add a point to the cows\n\n";
	
	do
	{
		displayInterface ();
	} while (playAgain ());
}

std::vector<int> genFourRandomNum ()
//Generates four unique numbers in a vector
{
	std::vector<int> randomNumbers;

	//obtains a random number from hardware then seeds it to the generator with the defined range from 0 - 9
	constexpr int rangeLowerLimit = 0, rangeUpperLimit = 9, generateLimit = 4;
	std::random_device randomNumber;
	std::mt19937 generatedSeed (randomNumber ());
	std::uniform_int_distribution<> distribution (rangeLowerLimit, rangeUpperLimit);

	int counter = 0;
	while (counter < generateLimit)
	{
		int randomValue = distribution (generatedSeed);
		//Only generate unique numbers
		if (std::find (std::begin (randomNumbers), std::end (randomNumbers), randomValue) == std::end (randomNumbers))	
		{
			randomNumbers.push_back (randomValue);
			++counter;
		}
	}

	return randomNumbers;
}

void displayInterface ()
//Displays the game interface and handles all the inputs
/*
	Expected output
	Try 1  |   Your Guess: 1234
	Bull 0 |   Cow 0
*/

{
	int count = 1, bull = 0, cow = 0;
	std::vector<int> guess;
	std::vector<int> randomNumbers = genFourRandomNum ();
	constexpr int winCondition = 4;

	//For debugging purposes only
	/*
		std::cout << "Debug: ";
		for (int counter : randomNumbers)
			std::cout << counter;
		std::cout << '\n';
	*/

	while (bull != winCondition)
	{
		std::cout << "Try " << count << "\t|" << "    Your Guess: ";
		guess = getUserGuess ();
		
		if (guess[0] != -1)
		{
			bull = calculateBull(guess, randomNumbers);
			cow = calculateCow (guess, randomNumbers);
			std::cout << "Bull " << bull << "\t|" << "    Cow " << cow << "\n\n";
			++count;
		}

		if (bull == winCondition)
		{
			std::cout << "Congratulations, you won!, the number is ";
			for (int counter : randomNumbers)
				std::cout << counter;
			std::cout << " and it took you " << count - 1 << " tries to win.\n";
		}
	}
}

std::vector<int> getUserGuess ()
//Gets the user guess for the game and store each digit as a vector
//Pre-condition: The input must be a 4 digit integer
//Post-condition: Input must not be a string integer
{
	std::vector<int> guess;
	std::string userInput;
	bool flag = false;

	while (true)
	{
		try
		{
			std::cin >> userInput;

			if (std::cin.fail () || userInput.size() != 4)
			{
				std::cin.clear ();
				std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');
				error ("Input is not a 4 digit.");
			}
			else
			{
				for (size_t counter = 0; counter < userInput.size (); ++counter)
				{
					if (userInput [counter] >= '0' && userInput [counter] <= '9')
						flag = true;
					else
					{
						flag = false;
						break;
					}
				}

				if (flag)
				{
					for (size_t counter = 0; counter < userInput.size (); ++counter)
						guess.push_back (userInput [counter] - '0');
					return guess;
				}	
				else
				{
					std::cin.clear ();
					std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');
					error ("Input is not a digit");
				}
			}
		}
		catch (std::runtime_error &e)
		{
			std::cerr << "Runtime error: " << e.what () << '\n';
			guess.push_back (-1);
			return guess;
		}

	}
}

int calculateBull (std::vector<int> userGuess, std::vector<int> randomNumbers)
//Calculates the bull - if the user guess is correct based from the random number
//and in the right position, add a point to the bull.
{
	int count = 0;

	for (size_t counter = 0; counter < userGuess.size (); ++counter)
	{
		if (userGuess [counter] == randomNumbers [counter])
			++count;
	}

	return count;
}

int calculateCow (std::vector<int> userGuess, std::vector<int> randomNumbers)
//Calculates the cow - if the user guess is correct based from the random number
//but not in the right position, add a point to the cow.
{
	int count = 0;
	int key = 0;
	for (size_t counter = 0; counter < randomNumbers.size (); ++counter)
	{
		key = userGuess [counter];
		if (std::find (randomNumbers.begin (), randomNumbers.end (), key) != randomNumbers.end ())
			++count;
	}

	return count;
}

bool playAgain ()
//Prompts the user if they want to play again 
//Post-condition: Choice must be either capitalized Y or N only.
{
	char choice;
	try
	{
		while (true)
		{
			std::cout << "Do you want to play again?(Y/N): ";
			std::cin >> choice;

			if (std::cin.fail () || choice != 'Y' && choice != 'N')
			{
				std::cin.clear ();
				std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');
				error ("Invalid Input!");
			}
			else
			{
				std::cout << '\n';
				if (choice == 'Y')
					return true;
				if (choice == 'N')
					return false;
			}
		}
	}
	catch (std::runtime_error &e)
	{
		std::cerr << "Runtime error: " << e.what () << " Exiting..." << '\n';
		return false;
	}
}

void error (std::string s)
//Throws a runtime error
{
	throw(std::runtime_error (s));
}