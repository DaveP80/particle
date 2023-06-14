class Solution {
    //Leet 424.
    // You are given a string s and an integer k. You can choose any character of the string and 
    // change it to any other uppercase English character. You can perform this operation at most k times.
    // Return the length of the longest substring containing the same letter you can get after 
    // performing the above operations.
    // Input: s = "ABAB", k = 2
    // Output: 4
    // Explanation: Replace the two 'A's with two 'B's or vice versa.
    public int characterReplacement(String s, int k) {
    int count = 0;
    int maxLength = 0;
    int left = 0;
    int right = 0;
    // Add a sentinel character to simplify the logic
    String modifiedString = "_" + s;

    for (int i = 1; i < modifiedString.length(); i++) {
        if (modifiedString.charAt(i) == modifiedString.charAt(i - 1)) {
            right = i;
        } else {
            left = right;
            right = i;
        }

        count = right - left;
        maxLength = Math.max(maxLength, count);
    }

    // If the input string is empty, the maximum length should be 0
    // Otherwise, at least one character exists, so the minimum length should be 1
    return maxLength > 0 ? maxLength : s.length() > 0 ? 1 : 0;
        
    }
}