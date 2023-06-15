#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution
{
    // Leet 16 3Sum Closest
    //  Given an integer array nums of length n and an integer target, find three integers in nums such that the
    //  sum is closest to target.
    //  Return the sum of the three integers.
    //  You may assume that each input would have exactly one solution.
    //  Input: nums = [-1,2,1,-4], target = 1
    //  Output: 2
    //  Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        std::vector<int> res;
        for (int j = 0; j < nums.size() - 2; j++)
        {
            if (j > 0 && nums[j] == nums[j - 1])
            {
                continue; // Skip duplicate elements
            }
            int left = j + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[j] + nums[left] + nums[right];

                if (sum == target)
                {
                    return sum;
                }
                else if (sum < target)
                {
                    res.push_back(sum);
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++; // Skip duplicate elements
                    }
                    left++;
                }
                else
                {
                    res.push_back(sum);
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--; // Skip duplicate elements
                    }
                    right--;
                }
            }
        }
        sort(res.begin(), res.end());
        int left = 0;
        int right = res.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (res[mid] < target)
            {
                left = mid + 1;
            }
            else if (res[mid] > target)
            {
                right = mid - 1;
            }
        }
        // At this point, left and right are pointing to the closest potential neighbors
        // We need to compare both neighbors and return the one closest to the target
        if (left >= res.size())
        {
            return res[right];
        }
        else if (right < 0)
        {
            return res[left];
        }
        else
        {
            int diffLeft = std::abs(res[left] - target);
            int diffRight = std::abs(res[right] - target);

            if (diffLeft <= diffRight)
            {
                return res[left];
            }
            else
            {
                return res[right];
            }
        }
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {5, 3, 7, 4, 7, -3, 25, 18, 73, 55};
    int ans = sol.threeSumClosest(nums, 42);
    cout << ans << "\n";
    // 40
    return 0;
}