/**
Leetcode Dynamic Programming
No. 32 Longest Valid Parentheses
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
 */
var longestValidParentheses = function(s) {
    const stack = [-1];
    let maxLen = 0;
  
    for (let i = 0; i < s.length; i++) {
      if (s[i] == '(') {
        stack.push(i);
      } else {
        stack.pop();
        if (stack.length == 0) {
          stack.push(i);
        } else {
          maxLen = Math.max(maxLen, i - stack[stack.length - 1]);
        }
      }
    }
  
    return maxLen;
  };