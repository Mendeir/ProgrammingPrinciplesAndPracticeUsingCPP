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
	switch (t.kind)						//see which kind of token it is
	{
		case '+':						//read and evaluate an expression, then do an addition
			return left + expression ();

		case '-':						//read and evaluate an expression, then do a subtraction
			return left - expression ();

		default:						//return the value of an expression
			return left;
	}
}

												