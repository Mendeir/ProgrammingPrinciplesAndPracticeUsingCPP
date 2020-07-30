#include "std_lib_facilities.h"

int main ()
{
    
    vector<string> disliked { "Brocolli", "Paksiw", "Amazing" };
    vector<string> words;
    

    for (string temp; cin >> temp;)
        words.push_back (temp);

    for (string counter : words)
    {
        bool flag { false };
        for (string counter2 : disliked)
        {
            if (counter == counter2)
                flag = true;
        }

        if (flag)
            cout << "BLEEP" << ' ';
        else
            cout << counter << ' ';
    }


    return 0;
}