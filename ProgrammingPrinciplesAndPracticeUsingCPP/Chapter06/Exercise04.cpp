/*
Write a program where you first enter a set of name - and -value pairs, such as Joe 17 and Barbara 22. 
For each pair, add the name to a vector called names and the number to a vector called scores (in 
corresponding positions, so that if names [7] == "Joe" then scores [7] == 17).Terminate input with NoName 0. 
Check that each name is unique and terminate with an error message if a name is entered twice.Write out 
all the (name, score) pairs, one per line.
*/

#include <iostream>
#include <string>
#include <vector>

class NameValue
{
	private:
		std::string names;
		int scores;
	
	public:
		//Constructors
		NameValue ();
		NameValue (std::string givenNames, int givenScores);

		//Getters
		std::string getName () const;
		int getScore () const;
};


void error (std::string s);
void fillRecords (std::vector<NameValue> &givenRecord);
void displayRecords (const std::vector<NameValue> &givenRecord);



int main ()
{
	try 
	{
		std::vector<NameValue> records;

		fillRecords (records);
		displayRecords (records);
	}
	catch(std::runtime_error &e)
	{
		std::cerr << "Runtime error: " << e.what () << " Exiting..." << '\n';
	}

	return 0;
}

void fillRecords (std::vector<NameValue> &givenRecord)
{
	const std::string loopNameTerminate = { "NoName" };
	constexpr int loopScoreTerminate = { 0 };
	std::string userNameInput;
	int userScoreInput { 0 };
	
	std::cout << "Enter a name followed by the score that is separated by a whitespace." << '\n';
	std::cout << "To terminate/stop the program, enter NoName 0" << '\n';
	
	while (true)
	{
		std::cin >> userNameInput >> userScoreInput;

		if (userNameInput == loopNameTerminate || userScoreInput == loopScoreTerminate)
			break;

		NameValue newRecord (userNameInput, userScoreInput);
		givenRecord.push_back (newRecord);
	}
}

void displayRecords (const std::vector<NameValue> &givenRecord)
{
	if (givenRecord.empty ()){
		std::cout << "Record is Empty!";
		return;
	}

	for (int counter = 0; counter < givenRecord.size (); ++counter)
		std::cout << givenRecord [counter].getName () << " " << givenRecord [counter].getScore () << '\n';
}

//Constructors
NameValue::NameValue ()
{
	names = ' ';
	scores = 0;
}

NameValue::NameValue (std::string givenNames, int givenScores)
{
	names = givenNames;
	scores = givenScores;
}

//Getters
std::string NameValue::getName () const
{
	return names;
}

int NameValue::getScore () const
{
	return scores;
}

//Outside Class Functions
void error (std::string s)
{
//Throws a runtime error with the given string
	throw (std::runtime_error (s));
}