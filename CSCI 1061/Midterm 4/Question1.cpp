#include <iostream>
#include <vector>
#include <string>
// Add headers as needed
#include <algorithm>

using namespace std;

// Do not change the gen_random function function
string gen_random(int len)
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    char *s = new char[len + 1];

    for (int i = 0; i < len; ++i)
    {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    s[len] = 0;

    string str(s);
    delete[] s;

    return str;
}

bool compareAnscending(string a, string b, int pos)
{
    if (int(a[pos]) < int(b[pos]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool compareDescending(string a, string b, int pos)
{
    if (int(a[pos]) > int(b[pos]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void sort(vector<string> &v, bool order, int letter_position)
{
    int sz = 5;
    //Placing strings after comparison
    string s[5];
    //Counter for position in array
    int x;

    //Ascending Sorting 
    if (order == 1)
    {
        for (int i = 0; i < sz; i++)
        {
            x = 0; //Reset counter
            for (int j = 0; j < sz; j++)
            {
                bool a = compareAnscending(v[i], v[j], letter_position);
                if (a == true)
                {
                    x++; //Check what value it has compared to others
                }
            }
            s[x] = v[i]; //Place it in correct position
        }
    }
    //Descending Sort
    if (order == 0)
    {
        for (int i = 0; i < sz; i++)
        {
            x = 0;
            for (int j = 0; j < sz; j++)
            {
                bool a = compareDescending(v[i], v[j], letter_position);
                if (a == true)
                {
                    x++;
                }
            }
            s[x] = v[i];
        }
    }
    //Pop current vector
    for (int k = 0; k < sz; k++)
    {
        v.pop_back();
    }
    //Return sorted vector
    for (int o = 0; o < sz; o++)
    {
        v.push_back(s[o]);
    }
}

// Do not change the main function
int main()
{
    // Setting up data
    srand(0);
    vector<string> v;
    int len = 5;
    for (int i = 0; i < 5; ++i)
    {
        v.push_back(gen_random(len));
    }

    // Printing our data
    cout << "Checking data" << endl;
    typedef vector<string>::iterator Itr_v;
    for (Itr_v i = v.begin(); i != v.end(); ++i)
    {
        cout << "\t" << *i << endl;
    }

    // We assume that the letters starts at 0
    int letter_position = 0;
    bool order = true;
    cout << "Sorting using letter position: " << letter_position << endl;
    cout << "Order ascending: " << order << endl;
    sort(v, order, letter_position);
    typedef vector<string>::iterator Itr_v;
    for (Itr_v i = v.begin(); i != v.end(); ++i)
    {
        cout << "\t" << *i << endl;
    }

    order = false;
    cout << "Sorting using letter position: " << letter_position << endl;
    cout << "Order ascending: " << order << endl;
    sort(v, order, letter_position);
    typedef vector<string>::iterator Itr_v;
    for (Itr_v i = v.begin(); i != v.end(); ++i)
    {
        cout << "\t" << *i << endl;
    }

    // We assume that the letters starts at 0
    letter_position = 3;
    order = true;
    cout << "Sorting using letter position: " << letter_position << endl;
    cout << "Order ascending: " << order << endl;
    sort(v, order, letter_position);
    typedef vector<string>::iterator Itr_v;
    for (Itr_v i = v.begin(); i != v.end(); ++i)
    {
        cout << "\t" << *i << endl;
    }

    order = false;
    cout << "Sorting using letter position: " << letter_position << endl;
    cout << "Order ascending: " << order << endl;
    sort(v, order, letter_position);
    typedef vector<string>::iterator Itr_v;
    for (Itr_v i = v.begin(); i != v.end(); ++i)
    {
        cout << "\t" << *i << endl;
    }

    return 0;
}