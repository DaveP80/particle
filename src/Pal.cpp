#include <iostream>
using namespace std;

// Given a string s, return the longest 
// palindromic substring in s.

    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;

        while (i<j) {
            if (s.substr(i, 1) != s.substr(j, 1)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

string longestPalindrome(string s) {

        if (s == "" || s.length() < 2) {
            return s;
        }

        string longest = s.substr(0,1);

        for (int i = 1; i<= s.length(); i++) {
            for (int j = 0; j<= s.length()-i; j++) {
                string substr = s.substr(j, i);
                
                if (substr.length() > longest.length() && isPalindrome(substr)) {
                    longest = substr;
                }
            }
        }
    return longest;  
    }

int main() {

    string longs = longestPalindrome("nmbghghrtrtxuaqqbkb");
    return 0; //ghg
}