#include "std_lib_facilities.h"

void get_name_score_input (vector<string> &names, vector<int> &scores);
void search_name (const vector<string> names, const vector<int> scores);
void search_score (const vector<string> names, const vector<int> scores);
void display_name_score (const vector<string> names, const vector<int> scores);
bool check_name_duplicate (const vector<string> names, const string name_input);

int main ()
{
	vector<string> names;
	vector<int> scores;

	while (true)
	{
		cout << "NAME AND SCORE RECORDS\n";

		cout << "\n\t1. Input names and scores\n" 
			 << "\t2. Search for name\n" 
			 << "\t3. Search for score\n" 
			 << "\t4. Display all names and scores\n"
			 << "\t5. Exit\n";
		
		cout << "Enter your choice: ";
		char choice { ' ' };
		cin >> choice;

		switch (choice)
		{
			case '1':
				get_name_score_input (names, scores);
				cout << '\n';
				break;

			case '2':
				search_name (names, scores);
				cout << '\n';
				break;

			case '3':
				search_score (names, scores);
				cout << '\n';
				break;

			case '4':
				display_name_score (names, scores);
				cout << '\n';
				break;

			case '5': 
				exit (1);
				break;

			default:
				cout << "Invalid input! Please try again.\n\n";
		}
	}

	return 0;
}

void get_name_score_input (vector<string> &names, vector<int> &scores)
{
	cout << "\nEnter unique name and score which is separated by a space:\n";
	cout << "Type NoName 0 to exit\n";
	
	const string loop_name_terminate { "NoName" };
	constexpr int loop_score_terminate { 0 };
	string name_input { " " }; 
	int score_input { 0 };


	while (name_input != loop_name_terminate || score_input != loop_score_terminate)
	{
		cin >> name_input >> score_input;
		if (cin.fail ())
		{
			cout << "Error: Invalid output! Please try again.\n";
			cin.clear ();
		}
		else
		{
			if (check_name_duplicate(names, name_input))
			{
				names.push_back (name_input);
				scores.push_back (score_input);
			}
			else
				cout << "Error: The name " << name_input << " has already been stored.\n";
		}
	}
}

void search_name (const vector<string> names, const vector<int> scores)
{
	string name { " " };
	char choice { ' ' };
	int score_index { 0 };
	bool flag { false };
	const char loop_terminate { 'n' };
	constexpr int lower_boundary { 0 };

	while (choice != loop_terminate)
	{
		cout << "\nWhat name do you want to search? ";
		cin >> name;

		for (size_t counter = lower_boundary; counter < names.size (); ++counter)
		{
			if (names [counter] == name)
			{
				score_index = counter;
				flag = true;
				break;
			}
		}

		if (flag)
		{
			cout << "The name " << name << " has a score of " << scores [score_index] << '\n';
			flag = false;
		}
		else
			cout << "The name " << name << " is not found.\n";

		cout << "Input n to exit, type anything to continue: ";
		cin >> choice;
	}


}

void search_score (const vector<string> names, const vector<int> scores)
{
	int score { 0 };
	char choice { ' ' };
	bool flag { false };
	const char loop_terminate { 'n' };
	constexpr int lower_boundary { 0 };

	while (choice != loop_terminate)
	{
		cout << "\nWhat score do you want to search? ";
		cin >> score;

		for (size_t counter = lower_boundary; counter < names.size (); ++counter)
		{
			if (scores [counter] == score)
			{
				cout << names [counter] << " ";
				flag = true;
			}
		}

		if (flag)
		{
			cout << "are the names with a score of " << score << '\n';
			flag = false;
		}
		else
			cout << "The score of " << score << " is not found.\n";

		cout << "Input n to exit, type anything to continue: ";
		cin >> choice;
	}


}

void display_name_score (const vector<string> names, const vector<int> scores)
{
	cout << "\nThe names and scores that has been accepted are:\n";
	for (size_t counter = 0; counter < names.size () - 1; ++counter)
	{
		cout << names [counter] << " " << scores [counter] << '\n';
	}
}

bool check_name_duplicate (const vector<string> names, const string name_input)
{
	for (string counter : names)
	{
		if (counter == name_input)
			return false;
	}

	return true;
}