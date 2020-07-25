#include "std_lib_facilities.h"

int main ()
{

	string first_name { "???" };

	cout << "Enter the first name of the person you want to write to: ";
	cin >> first_name;

	cout << "\nDear " << first_name << ",\n";
	cout << "\tHow are you? I am amazing and it's nice that I am able to write a letter to you\n";

	string friend_name { "???" };
	cout << "\nEnter a person that you want to talk about: ";
	cin >> friend_name;

	cout << "\n\tHave you seen " << friend_name << " lately?\n";

	char friend_sex { 0 };
	cout << "\nEnter 'm' if your friend is a male or 'f' if your friend is a female: ";
	cin >> friend_sex;

	if (friend_sex == 'm')
		cout << "\n\tIf you see " << friend_name << " please ask him to call me\n";
	if (friend_sex == 'f')
		cout << "\n\tIf you see " << friend_name << " please ask her to call me\n";

	int age { 0 };
	cout << "\nHow old are you right now? ";
	cin >> age;

	if (age <= 0 || age >= 110)
		simple_error ("you're kidding!\n");
	else
		cout << "\n\tI heard you just had you birthday and you are " << age << " years old.\n";

	if (age < 12)
		cout << "\tNext year you will be " << age + 1 << '\n';
	if (age == 17)
		cout << "\tNext year you will be able to vote.\n";
	if (age >= 70)
		cout << "\tI hope that you are enjoying retirement.\n";

	cout << "\nYours sincerely,"
		 << "\n\nMG\n";


	return 0;
}