#include <vector>
#include <iostream>
// CodeWars
// Given an array of integers.
// Return an array, where the first element is the count of positives numbers and the second 
// element is sum of negative numbers. 0 is neither positive nor negative.
// If the input is an empty array or is null, return an empty array.
// For input [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15], 
// you should return [10, -65].

std::vector<int> countPositivesSumNegatives(std::vector<int> input)
{
    std::vector<int> res;
    if (input.empty()) return res;
    res.push_back(0);
    res.push_back(0);
    for (auto num: input) {
      if (num > 0) res[0]++;
      else if (num < 0) {
        res[1] += num;
      }
    }
    return res;
}
int main() {
    std::vector<int> ans = countPositivesSumNegatives({-2,5,-7,3,0,1,-9});
    for (auto item: ans) {
        std::cout << item << "\n";
    }
    return 0;
}