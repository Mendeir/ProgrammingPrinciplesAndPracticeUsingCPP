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
    int res5 = 7; 
    vector<int> v5 (10); 
    v5 [5] = res5; 
    cout << "5. Success!\n";

    //6. vector<int> v (10); v (5) = 7; if (v (5) != 7) cout << "Success!\n";
    //Error spotted : Used parenthesis instead of square brackets or .at() function
    //                Used != operator instead of == 
    vector<int> v6 (10);
    v6[5] = 7; 
    if (v6 [5] == 7) 
        cout << "6. Success!\n";

    //7. if (cond) cout << "Success!\n"; else cout << "Fail!\n";
    //Error spotted: No condition on if statement 
    if (v6[5] == 7) 
        cout << "7. Success!\n"; 
    else 
        cout << "Fail!\n";

    //8. bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
    //Error spotted : if statement condition is wrong thus requirement will never be met
    bool c8 = false; 
    if (!c8) 
        cout << "8. Success!\n"; 
    else 
        cout << "Fail!\n";

    //9. string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n";
    //Error spotted : mispelled the data type of 'bool', if statement will never execute due to the condition
    string s9 = "ape";
    bool c9 = "fool" < s9; 
    if (!c9) 
        cout << "9. Success!\n";

    //10. string s = "ape"; if (s=="fool") cout << "Success!\n";
    //Error spotted : if statement will never execute due to the condition
    string s10 = "ape"; 
    if (s10 != "fool") 
        cout << "10. Success!\n";
    
    //11. string s = "ape"; if (s=="fool") cout < "Success!\n";
    //Error spotted : if statement will never execute due to the condition, used relational operator on an output stream
    string s11 = "fool"; 
    if (s11 == "fool") 
        cout << "11. Success!\n";

    //12. string s = "ape"; if (s+"fool") cout < "Success!\n";
    //Error spotted : String is being concatenated instead of being expressed in the if statement, wrong data type on 
    //variable s or can be wrong operator in the if statement, used relational operator on an output stream
    bool s12 = "ape"; 
    if (s12 + "fool") 
        cout << "12. Success!\n";

    //13. vector<char> v(5); for (int i=0; 0<v.size(); ++i) ; cout << "Success!\n";
    //Error spotted : Expression will always be true thus it will loop forever, warning of signed and unsigned mismatch
    //mismatch as vector size will never be below 0
    vector<char> v13 (5);
    for (size_t i = 0; i < v13.size (); ++i); 
    cout << "13. Success!\n";

    //14. vector<char> v (5); for (int i = 0; i <= v.size (); ++i); cout << "Success!\n";
    //Error spotted : Due to the relational operator<=, the loop will go out of bounds, warning of signed and unsigned mismatch
    vector<char> v14 (5); 
    for (size_t i = 0; i < v14.size (); ++i); 
    cout << "14. Success!\n";


    //15. string s = "Success!\n"; for (int i = 0; i < 6; ++i) cout << s [i];
    //Error spotted : The loop will only go on fixed number thus, the whole string will not be displayed, warning of signed and unsigned mismatch
    string s15 = "15. Success!\n"; 
    for (size_t i = 0; i < s15.size(); ++i) 
        cout << s15 [i];

    //16. if (true) then cout << "Success!\n"; else cout << "Fail!\n";
    //Error spotted : Wrong syntax, 'then' is not a part of c++ syntax

    if (true)
        cout << "16. Success!\n";
    else
        cout << "Fail!\n";

    //17. int x = 2000; char c = x; if (c == 2000) cout << "Success!\n";
    //Error spotted : Wrong data type used in variable 'c', narrow conversion of char type overflows with implicit conversion which leads to loss of data.

    int x17 = 2000;
    int c17 = x17; 
    if (c17 == 2000) cout << "17. Success!\n";

    //18. string s = "Success!\n"; for (int i = 0; i < 10; ++i) cout << s [i];
    //Error spotted : The following loops goes out of bounds and is a fixed sized thus, different length of strings may lead to different results. 
    //warning of signed and unsigned mismatch
    string s18 = "18. Success!\n"; 
    for (size_t i = 0; i < s18.size(); ++i) 
        cout << s18 [i];

    //19. vector v (5); for (int i = 0; i <= v.size (); ++i); cout << "Success!\n";
    //Error spotted : Incomplete syntax in initializing a vector, no data type indicated in the vector, assumed data type is an int. 
    //warning of signed and unsigned mismatch
    vector<int> v (5);
    for (size_t i = 0; i <= v.size (); ++i); 
    cout << "19. Success!\n";

    //20. int i = 0; int j = 9; while (i < 10) ++j; if (j < i) cout << "Success!\n";
    //Error spotted : Loop will never end, the value being incremented is j instead of i which is the one being expressesd, magic constants.
    int i20 = 0; 
    int j20 = 9;
    while (i20 < 10) 
        ++i20; 
    if (j20 < i20) 
        cout << "20. Success!\n";

    //21. int x = 2; double d = 5 / (x–2); if (d == 2 * x + 0.5) cout << "Success!\n";
    //Error spotted : More of a logical error, e.g division of 0, different subtraction sign on my machine, many ways to fix this problem 
    //since the computation is not commented or expressed in fucntions. warning of arithmetic overflow due to datatype of a variable is 
    //being computed to a larger data type
    double x21 = 2;
    double d21 = 5.0 / x21 + 2;
    if (d21 == 2 * x21 + 0.5)
        cout << "21. Success!\n";

    //22. string<char> s = "Success!\n"; for (int i = 0; i <= 10; ++i) cout << s [i];
    //Error spotted : Wrong use of syntax, assumed that the user is try to maked a string, loop size is a fixed size leading to out of bounds or 
    //lack of iterations depending on the length of string, warning of signed and unsigned mismatch
    string s22 = "22. Success!\n"; 
    for (size_t i = 0; i <= s22.size(); ++i) 
        cout << s22 [i];

    //23. int i = 0; while (i < 10) ++j; if (j < i) cout << "Success!\n";
    //Error spotted : j is uinitialized, the loop will go forever as the variable being express does not change
    int i23 = 0;
    int j23 = 5;
    while (i23 < 10) ++i23; 
        if (j23 < i23) cout << "23. Success!\n";

    //24. int x = 4; double d = 5 / (x–2); if (d = 2 * x + 0.5) cout << "Success!\n";
    //Error spotted : It works but on my machine subtraction operator is different, and we are assigning on an if statement rather than comparing variable
    //or values which makes this a logical error. warning of arithmetic overflow due to datatype of a variable is being computed to a larger data type
    double x24 = 4;
    double d24 = 5.0 / (x24 - 2);
    if (d24 == x24 / 2.0 + 0.5)
         cout << "24. Success!\n";

    //25. cin << "Success!\n";
    //Error spotted : An output operator<< is being used in an input stream
    cout << "25. Success!\n";

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