#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Given an array of integers nums and an integer target, return indices of the 
// two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and 
// you may not use the same element twice.

// You can return the answer in any order.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2, 0);

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
        }

        return result; 
        }
};

//Or, Same solution but using a Hash Table

class SolutionB {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // create a hash map to store complements and their indices
        vector<int> result(2, 0); // create a vector to store the result

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                // we found a complement, return its index and the current index
                result[0] = map[complement];
                result[1] = i;
                return result;
            }
            // otherwise, store the current number and its index in the hash map
            map[nums[i]] = i;
        }

        return result; // if no solution found, return an empty vector
    }
};