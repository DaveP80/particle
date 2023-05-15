#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
// You are given nums, an array of positive integers of size 2 * n. You 
// must perform n operations on this array.
// In the ith operation (1-indexed), you will:
// Choose two elements, x and y.
// Receive a score of i * gcd(x, y).
// Remove x and y from nums.
// Return the maximum score you can receive after performing n operations.

// The function gcd(x, y) is the greatest common divisor of x and y.
// Example 1:
// Input: nums = [1,2]
// Output: 1
// Explanation: The optimal choice of operations is:
// (1 * gcd(1, 2)) = 1
// Example 2:
// Input: nums = [3,4,6,8]
// Output: 11
// Explanation: The optimal choice of operations is:
// (1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        unordered_map<int, int> cache;
        return dfs(0, 1, nums, cache);
    }
    
    int dfs(int mask, int op, vector<int>& nums, unordered_map<int, int>& cache) {
        if (cache.find(mask) != cache.end()) {
            return cache[mask];
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if ((1 << i) & mask || (1 << j) & mask) {
                    continue;
                }
                int newMask = mask | (1 << i) | (1 << j);
                int score = op * gcd(nums[i], nums[j]);
                cache[mask] = max(cache[mask], score + dfs(newMask, op + 1, nums, cache));
            }
        }
        return cache[mask];
    }
    
    int gcd(int a, int b) {
        if (a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }
};

int main() {

    Solution sol;
    vector<int> nums = {1,2,3,4,5,6};
    int res = sol.maxScore(nums);
    cout << res << "\n";
};