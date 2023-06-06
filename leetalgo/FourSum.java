import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class FourSum {
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
        public static List<List<Integer>> fourSum(int[] nums, int target) {
            Arrays.sort(nums);
            List<List<Integer>> res = new ArrayList<>();
            for (int i = 0; i < nums.length - 3; i++) {
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue; // Skip duplicate elements
                }
                for (int j = i + 1; j < nums.length - 2; j++) {
                    if (j > i + 1 && nums[j] == nums[j - 1]) {
                        continue; // Skip duplicate elements
                    }
                    int left = j + 1;
                    int right = nums.length - 1;

                    while (left < right) {
                        long sum = (long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right];

                        if (sum == target) {
                            res.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));

                            while (left < right && nums[left] == nums[left + 1]) {
                                left++; // Skip duplicate elements
                            }
                            while (left < right && nums[right] == nums[right - 1]) {
                                right--; // Skip duplicate elements
                            }
                            left++;
                            right--;
                        } else if (sum < target) {
                            left++;
                        } else {
                            right--;
                        }
                    }
                }
            }
            return res;
        }
    public static void main(String[] args) {


        List<List<Integer>> ans = fourSum(new int[]{-5, -5, -2, -2, -1, 1, 1, 1, 3, 4, 4}, 3);

        System.out.println(ans);
        //[[-5, 1, 3, 4], [-2, -2, 3, 4], [-2, 1, 1, 3]]
        
    }
}