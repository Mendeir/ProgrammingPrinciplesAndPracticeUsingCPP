#include <std_lib_facilities.h>

class Token
{
	public:
		char kind;
		double value;
};

Token get_token ();
vector<Token> tok;

//Functions to build grammar rules for an expression
Token get_token ();		//reads characters and compose tokens and uses cin
double expression ();		//deals with + and -   calls term() ang get_token() 
double term ();			//deals with *, / and %		calls primary() and get_token()
double primary ();			//deals with number and parentheses		calls expression() and get_token()


int main ()
{

}

/*
Expression:
	Term
	Expression '+' Term
	Expression '-' Term

*/

double expression ()
{
	double left = term ();				//read and evaluate a term
	Token t = get_token ();				//get the next token
	while (true)
	{
		switch (t.kind)						//see which kind of token it is
		{
			case '+':						//evaluate Term and add
				left += term ();
				t = get_token ();
				break;

			case '-':						//evaluate Term and subtract
				left -= term ();
				t = get_token ();
				break;

			default:						//no more + or - return the answer;
				return left;
		}
	}
}

/*
Term:
	Primary
	Term '*' Primary
	Term '/' Primary
*/

double term ()
{
	double left = primary ();
	Token t = get_token ();
	while (true)
	{
		switch (t.kind)
		{
			case '*':
				left *= primary ();
				t = get_token ();
				break;
			
			case '/':
			{
				double d = primary ();

				if (d == 0)
					error ("Divide by zero");

				left /= d;
				t = get_token ();
				break;
			}

			default:
				return left;

		}
	}
}

/*
Primary:
	Number 
	'(' Expression ')'

*/

double Primary ()
{
	Token t = get_token ();
	switch (t.kind)
	{
		case '(':									//handle '(' expression ')'
		{
			double d = expression ();
			t = get_token ();
			if (t.kind != ')')
				error (" ')' expected");
				return d;
		}
		case '8':									//Used 8 to represent number 
			return t.value;							//return numbers value

		default:
			error ("primary expected");

	}
}

