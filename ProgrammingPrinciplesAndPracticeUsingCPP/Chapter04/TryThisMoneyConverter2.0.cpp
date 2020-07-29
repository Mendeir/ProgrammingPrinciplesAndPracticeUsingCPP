#include "std_lib_facilities.h"

int main ()
{
	constexpr double dollar_per_yen { 0.0095 };
	constexpr double dollar_per_kroner { 0.11 };
	constexpr double dollar_per_pound { 1.30 };

	double money_input { 0 };

	char unit { ' ' };

	cout << "MONEY CONVERTER: YEN, KRONER, POUNDS TO DOLLAR\n";
	cout << "\nEnter how much you want to convert into dollars followed by a unit (y, k, or p):\n";
	cin >> money_input >> unit;

	switch (unit)
	{

		case 'y':
			cout << "\nFor every " << money_input << " yen, you have " << money_input * dollar_per_yen << " dollar/s.\n";
			break;

		case 'k':
			cout << "\nFor every " << money_input << " kroner, you have " << money_input * dollar_per_kroner << " dollar/s.\n";
			break;

		case 'p':
			cout << "\nFor every " << money_input << " pound/s, you have " << money_input * dollar_per_pound << " dollar/s.\n";
			break;

		default:
			cout << "\nSorry can't identify unit entered.\n";

	}

		
	return 0;
}