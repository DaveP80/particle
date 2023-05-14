#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate elements

        int l = i + 1, r = n - 1;

        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0) { // triplet is found
                res.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1]) l++; // skip duplicate elements
                while (l < r && nums[r] == nums[r - 1]) r--; // skip duplicate elements
                l++;
                r--;
            } else if (sum < 0) {
                l++;
            } else {
                r--;
            }
        }
    }
    return res;
}
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -3, 6, -5, 7, 1};
    vector<vector<int>> triplets = sol.threeSum(nums);

    for (vector<int> triplet : triplets) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;

}