#include <iostream>
#include <vector>
using namespace std;

// Given a string s, return the longest
// palindromic substring in s.
bool isPalindrome(const string &s, int i, int j)
{

    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

string longestPalindrome(string s)
{
    if (s == "" || s.length() < 2)
    {
        return s;
    }

    string longest = s.substr(0, 1);

    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 0; j <= s.length() - i; j++)
        {

            if (i > longest.length() && isPalindrome(s, j, j + i - 1))
            {
                longest = s.substr(j, i);
            }
        }
    }
    return longest;
}

int main()
{

    string longs = longestPalindrome("whfuyujujqc");
    cout << longs << "\n";
    return 0; // uyu
}