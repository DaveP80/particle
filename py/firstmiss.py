# LeetCode
# 32. Longest Valid Parentheses
def firstMissingPositive(nums):
        z = len(nums) + 1
        arr = [i for i in range(1, z)]
        idx = 0
        while True:
            if nums[idx] in range(1, z):
                try:
                    arr.remove(nums[idx])
                except:
                    None
            if idx+1 < len(nums) and nums[idx+1] > len(nums):
                idx += 2
            else:
                idx += 1
            if idx >= len(nums):
                break
        if not arr:
            return z
        else:
            return arr[0]