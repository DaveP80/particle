#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

//Given an integer array nums sorted in non-decreasing order, 
//return an array of the squares of each number sorted in non-decreasing order.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int left = 0, right = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[i] = nums[left] * nums[left];
                left++;
            } else {
                result[i] = nums[right] * nums[right];
                right--;
            }
        }
        return result;
        
    }
};
int main() {
    return 0;
}

