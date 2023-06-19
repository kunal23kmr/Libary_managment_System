// Typing test...

#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <map>

using namespace std;

float total, attempted = 0, correct = 0, incorrect = 0;

void show_accurecy()
{
    cout << "\n\n\nYour Typing accurecy is: " << (correct / attempted) * 100 << endl;
}

void show_typing_result(map<char, float> &wrong, map<char, float> &right)
{
    map<char, float> percent_error;
    // new map to store the % difficultyzzzz......

    map<char, float>::iterator itr;
    for (itr = wrong.begin(); itr != wrong.end(); ++itr) /// exit from the loop when traversed whole wrong map
    {
        float percent = (wrong[itr->first] * 100) / (wrong[itr->first] + right[itr->first]);
        percent_error[itr->first] = percent;
    }

    char difficult_char;
    float difficulty = 0;

    for (itr = percent_error.begin(); itr != percent_error.end(); ++itr)
    {

        if (itr->second >= difficulty)
        {
            difficult_char = itr->first;
            difficulty = itr->second;
        }
    }

    cout << "\n\nMost difficult Character is: " << difficult_char << endl;
    cout << "The percentage error is " << difficulty << "%." << endl;
    cout << "Tomtal " << incorrect << " Times inputed wrong charector." << endl
         << endl
         << endl;
}

int main()
{

    system("clear||cls");
    string poem = "The lonely mountains o're,\nAnd the resounding shore,\nA voice of weeping heard, and loud lament;\nFrom haunted spring, and dale\nEdg'd with poplar pale\nThe parting Genius is with sighing sent,\nWith flowre-inwov'n tresses torn\nThe Nimphs in twilight shade of tangled thickets mourn.";
    total = poem.size();

    map<char, float> myMap_wrong;
    // storing the char and the number of wrongzzzz...

    map<char, float> myMap_right;
    // to store the wrong char frequencyzzzz...

    int count = total + 1;
    cout << "\n";
    for (int i = 1; i < 34; i++)
        cout << "=";

    cout << "\n Welcome to Typing Speed test..."
         << endl;

    cout << "";

    for (int i = 1; i < 34; i++)
        cout << "=";

    cout << "\n\nYou can press 'ESC' to stop the test.\n\n\nType the below lines:" << endl
         << "----------------------\n\n"
         << poem << "\n\n\n"
         << endl;
    cout << "Start Typing:\n";

    int i = 0;
    int x = 1;

    while (count--)
    {
        if (poem[i] == '\n' || count == total)
        {
            if (poem[i] == '\n')
            {
                i++;
            }
            cout << "\n\nFor line: " << x++ << endl;
            continue;
        }

        char enterred;
        enterred = getch();
        if (enterred == 27) // if ESC, then stop
        {
            break;
        }

        attempted++;
        cout << enterred;

        if (enterred == poem[i])
        {
            correct++;
        }
        else
        {
            incorrect++;
        }

        auto it = myMap_wrong.find(poem[i]);
        if (it != myMap_wrong.end()) // if present
        {
            if (enterred != poem[i]) // if entered is not same...
            {
                it->second++;
            }
            else // if entered is same...
            {
                auto it = myMap_right.find(poem[i]);
                it->second++;
            }
        }
        else // if not present- push it
        {
            if (poem[i] == enterred) // if entered right
            {
                myMap_wrong.insert({poem[i], 0});
                myMap_right.insert({poem[i], 1});
            }
            else // if entered wrong...
            {
                myMap_wrong.insert({poem[i], 1});
                myMap_right.insert({poem[i], 0});
            }
        }
        i++;
    }

    show_accurecy();
    show_typing_result(myMap_wrong, myMap_right);
    cout << "\n\nThank You for Using....";

    return 0;
}