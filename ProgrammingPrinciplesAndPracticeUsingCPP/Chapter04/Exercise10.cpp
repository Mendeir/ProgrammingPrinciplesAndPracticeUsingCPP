#include "std_lib_facilities.h"

vector<string> hands { "rock", "paper", "scissors" };
string get_player_hand ();
string get_computer_hand (string words_input);
int return_hands (char choice);
int judge_results (char player_hand, char computer_hand);

int main ()
{
	string player_hand { ' ' }, computer_hand;
	string words_input { "" };
	int player_score { 0 }, computer_score { 0 };
	constexpr int score_limit { 3 };
	
	cout << "ROCK, PAPER, SCISSORS\n";

	cout << "\nThe first to get " << score_limit << " wins!\n";
	
	//Will be used to generate random answers
	cout << "Any last words? ";
	getline (cin, words_input);


	cout << "\nInput 'r' for rock, 'p' for paper and 's' for scissors.\n";

	while (player_score != score_limit && computer_score != score_limit)
	{
		//Get their hands
		player_hand = get_player_hand ();
		computer_hand = get_computer_hand (words_input);
		
		//Display result
		cout << "\nYou picked " << player_hand << " and I picked " << computer_hand << '\n';

		switch (judge_results (player_hand [0], computer_hand [0]))
		{
			case 0:
				cout << "I win! :P\n";
				//For computer's input
				cout << "What can you say about that huh?! ";
				cin.ignore ();
				getline (cin, words_input);

				//add score
				++computer_score;
				break;
			case 1:
				cout << "You win! You're good\n";
				//For computer's input
				cout << "What you think about your win huh? ";
				cin.ignore ();
				getline (cin, words_input);

				//add score
				++player_score;

				break;
			case 2:
				cout << "Draw, No one won :(\n";
				//For computer's input
				cout << "How did you guessed my hand?! ";
				cin.ignore ();
				getline (cin, words_input);

				break;
		}

		cout << "Your score: " << player_score << " My score: " << computer_score << "\n\n";

	}

	if (player_score == score_limit)
		cout << "Congratulations! You won! Better luck to me next time I guess.\n";
	if (computer_score == score_limit)
		cout << "I won! Better luck next time :)\n";

	return 0;
}


string get_player_hand ()
{
	while (true)
	{
		char player_hand { ' ' };

		cout << "What will your choice be? ";
		cin >> player_hand;

		if (cin.fail() || (player_hand != 'r' && player_hand != 'p' && player_hand != 's'))
		{
			cin.clear ();
			cout << "\nHey, that's not a valid input! Try again fella!\n";
		}
		else
			return hands[return_hands(player_hand)];
	}
}

string get_computer_hand (string words_input)
{
	const int number_of_hands = hands.size ();
	return hands [words_input.size () % number_of_hands];
}

int return_hands (char choice)
{
	switch (choice)
	{
		case 'r':
			return 0;
			break;

		case 'p':
			return 1;
			break;

		case 's':
			return 2;
			break;

		default:
			return 0;
	}
}

int judge_results (char player_hand, char computer_hand)
{
	constexpr int lose { 0 }, win { 1 }, draw { 2 }; //lose and win for the player

	if (player_hand == computer_hand)
		return draw;

	if (player_hand == 'r')
	{
		if (computer_hand == 'p')
			return lose;
		if (computer_hand == 's')
			return win;
	}
	
	if (player_hand == 'p')
	{
		if (computer_hand == 'r')
			return win;
		if (computer_hand == 's')
			return lose;
	}

	if (player_hand == 's')
	{
		if (computer_hand == 'p')
			return win;
		if (computer_hand == 'r')
			return lose;
	}

	return draw;
}