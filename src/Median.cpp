#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Given two sorted arrays nums1 and nums2 of size m and n 
// respectively, return the median of the two sorted arrays.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    std::vector<int> merged(nums1.size() + nums2.size());

    std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());
    std::sort(merged.begin(), merged.end());
      int n = merged.size();
        if (n % 2 == 0) {
            return (double)(merged[n / 2 - 1] + merged[n / 2]) / 2;
        } else {
            return merged[n / 2];
        }
    }
};