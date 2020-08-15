#include "std_lib_facilities.h"

int main ()
try 
{
    //1. Cout << "Success!\n";
    cout << "Success!\n";

    //2. cout << "Success!\n;
    cout << "Success!\n";

    //3. cout << "Success" << !\n"
    cout << "Success" << "!\n";

    //4. cout << success << '\n';
    cout << "success" << '\n';

    keep_window_open ();
    return 0;

}

catch (exception& e)
{
    cerr << "error: " << e.what () << '\n';
    keep_window_open ();
    return 1;

}

catch (...)
{
    cerr << "Oops: unknown exception!\n";
    keep_window_open ();
    return 2;

}