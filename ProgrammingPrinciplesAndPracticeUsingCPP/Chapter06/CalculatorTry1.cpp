#include <iostream>
#include <limits>

void error (std::string s)
{
	throw (std::runtime_error (s));
}

int main ()
{
	while (true)
	{
		try 
		{
			std::cout << "Enter exrpession: ";
	
			int lval = 0, rval = 0;
			std::cin >> lval;

			if (std::cin.fail ())
			{
				std::cin.clear ();
				std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');
				error ("No first operand");
			}

			for (char op; std::cin >> op;)
			{
				if (std::cin.fail ())
				{
					std::cin.clear ();
					std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');
					error ("No second operand");
				}

				std::cin >> rval;

				if (std::cin.fail ())
				{
					std::cin.clear ();
					std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');
					error ("No third operand");
				}

				switch (op)
				{
					case '+':
						lval += rval;
						break;
					case '-':
						lval -= rval;
						break;
					case '*':
						lval *= rval;
						break;
					case '/':
						lval /= rval;
						break;
					default: 
						std::cout << "Result: " << lval << '\n';
						return 0;
				}
			}


		}
		catch (std::runtime_error (s))
		{
			std::cerr << "Runtime error: " << s.what () << '\n';
		}

	}

	return 0;
}