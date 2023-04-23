#include <unordered_set>
#include <iostream>
#include <string>
using namespace std;

// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0, maxLen = 0;
        std::unordered_set<char> charSet;

        while (i < n && j < n) {
            if (charSet.find(s[j]) == charSet.end()) {
            //use the j index, and then increment
            charSet.insert(s[j++]);
            maxLen = std::max(maxLen, j - i);
            } else {
            charSet.erase(s[i++]);
            }
        }

        return maxLen;
    }
};