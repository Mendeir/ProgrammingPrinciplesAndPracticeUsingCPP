#include "std_lib_facilities.h"

int main ()
try 
{
    //1. Cout << "Success!\n";
    //Error spotted : Capitalized 'c' on 'cout'
    cout << "1. Success!\n";

    //2. cout << "Success!\n;
    //Error spotted : Missing quotation marks at the end of string 
    cout << "2. Success!\n";

    //3. cout << "Success" << !\n"
    //Error spotted : Missing quotation marks before the start of string
    cout << "3. Success" << "!\n";

    //4. cout << success << '\n';
    //Error spotted : Missing double quotation marks on the start of string 
    cout << "4. Success!" << '\n';

    //5. string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
    //Error spotted : wrong data type used
    int res = 7; 
    vector<int> v1 (10); 
    v1 [5] = res; 
    cout << "5. Success!\n";

    //6. vector<int> v (10); v (5) = 7; if (v (5) != 7) cout << "Success!\n";
    //Error spotted : Used parenthesis instead of square brackets or .at() function
    //                Used != operator instead of == 
    vector<int> v2 (10);
    v2[5] = 7; 
    if (v2 [5] == 7) 
        cout << "6. Success!\n";

    //7. if (cond) cout << "Success!\n"; else cout << "Fail!\n";
    //Error spotted: No condition on if statement 
    if (v2[5] == 7) 
        cout << "7. Success!\n"; 
    else 
        cout << "Fail!\n";

    //8. bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
    //Error spotted : if statement condition is wrong thus requirement will never be met
    bool c = false; 
    if (!c) 
        cout << "8. Success!\n"; 
    else 
        cout << "Fail!\n";

    //9. string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n";
    //Error spotted : mispelled the data type of 'bool'
    string s = "ape";
    bool c = "fool" < s; 
    if (c) 
        cout << "9. Success!\n";


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