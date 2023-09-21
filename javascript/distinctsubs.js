/**LeetCode No. 115
 * Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.
Example 1:
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
 */
var numDistinct = function(s, t) {
    const m = s.length;
    const n = t.length;
    const dp = Array(m + 1)
      .fill(0)
      .map(() => Array(n + 1).fill(0));

    for (let i = 0; i <= m; i++) {
      dp[i][0] = 1;
    }

    console.log(dp.length, dp[0].length);
  
    for (let i = 1; i <= m; i++) {
      for (let j = 1; j <= n; j++) {
        if (s[i - 1] === t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[m][n];
  };

  const s = "rabbbit";
  const t = "rabbit";
  console.log(numDistinct(s, t)); // Output: 3