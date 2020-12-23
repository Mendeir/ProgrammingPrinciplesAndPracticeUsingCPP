#include <std_lib_facilities.h>

class Token
{
	public:
	char kind;
	double value;
};

class Token_stream
{
	private:
	//impelementation details
	bool full { false };		//Check if there is a token in the buffer
	Token buffer { ' ' };				//Keep a Token putback using putback()

	public:
	//user interface
	Token get ();				//get a Token (get())
	void putback (Token t);		//Put a token back
};


Token_stream ts;
vector<Token> tok;

//Functions to build grammar rules for an expression
double expression ();		//deals with + and -   calls term() ang get_token() 
double term ();				//deals with *, / and %	calls unique() and get_token()
int unique ();			// deals with ! and calls primary and get_token()
double primary ();			//deals with number and parentheses	calls expression() and get_token()


int main ()
{
	try
	{
		double val = 0;
		cout << "Welcome to our simple calculator. "
			<< "\nAccepted operators are + , -, *, / , (, ), { , } and !"
			<< "\nInput the character 'x' to quit and '=' to show the answer."
			<< "\nPlease enter expressions using floating - point numbers.\n\n";

		while (cin)
		{
			Token t = ts.get ();

			if (t.kind == 'q')
				break;

			if (t.kind == '=')
				cout << val << '\n';

			else
				ts.putback (t);
			val = expression ();
		}
		keep_window_open ();
	}
	catch (exception &e)
	{
		cerr << e.what () << '\n';
		keep_window_open ();
		return 1;
	}
	catch (...)
	{
		cerr << "exception \n";
		keep_window_open ();
		return 2;
	}
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
	Token t = ts.get ();				//get the next token from the token stream
	while (true)
	{
		switch (t.kind)					//see which kind of token it is
		{
			case '+':					//evaluate Term and add
				left += term ();
				t = ts.get ();
				break;

			case '-':					//evaluate Term and subtract
				left -= term ();
				t = ts.get ();
				break;

			default:
				ts.putback (t);			//put t back into the token stream
				return left;			//no more + or - return the answer
		}
	}
}

/*
Term:
	Unique
	Term '*' Primary
	Term '/' Primary
*/

double term ()
{
	double left = unique ();
	Token t = ts.get ();				//get the next token from the token stream
	while (true)
	{
		switch (t.kind)
		{
			case '*':
				left *= primary ();
				t = ts.get ();
				break;

			case '/':
			{
				double d = primary ();

				if (d == 0)
					error ("Divide by zero");

				left /= d;
				t = ts.get ();
				break;
			}

			default:
				ts.putback (t);			//put t back into the token stream
				return left;			//no more + or - return the answer
		}
	}
}

/*
	Unique: 
		Primary
		Unique '!' primary
*/


int unique () 
{
	int left = primary ();
	Token t = ts.get ();
	

	switch (t.kind)
	{
		case '!':
		{
			if (left == 0)
				return 1;

			int factorial = 1;


			for (int counter = 1; counter <= left; ++counter)
			{
				factorial *= counter;
			}

			return factorial;
		}

		default:
			ts.putback (t);			//put t back into the token stream
			return left;			//no more + or - return the answer
	}
}

/*
Primary:
	Number
	'(' Expression ')'

*/
double primary ()
{
	Token t = ts.get ();
	switch (t.kind)
	{
		case '{':
		{
			double d = expression ();
			t = ts.get ();
			if (t.kind != '}')
				error (" '}' expected");
			return d;
		}

		case '(':									//handle '(' expression ')'
		{
			double d = expression ();
			t = ts.get ();
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


//Class Token stream functions

/*
	Pre-condition: Check if there is no token in the buffer
*/
void Token_stream::putback (Token t)
{

	if (full)
		error ("putback() into a full buffer");

	buffer = t;			//copy t to buffer
	full = true;		//buffer is now full
}

//Read tokens
Token Token_stream::get ()
{
	if (full)				//check if there is a token
	{
		full = false;		//remove token from the buffer
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch)
	{
		case '=':			//for print
		case 'q':			//for quit
		case '!':
		case '{': case '}':
		case '(': case ')':
		case '+': case '-': case '*': case '/':
			return Token { ch };

		case '.':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			cin.putback (ch);				//put digit back into the input stream
			double val;
			cin >> val;						//read floating point number
			return Token { '8', val };		//let '8' represent a number
		}

		default:
			error ("Bad Token");
	}


}