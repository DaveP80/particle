#Given an integer array nums, move all 0's to the end of it while 
# maintaining the relative order of the non-zero elements.
# Note that you must do this in-place without making a copy of the array.
def moveZeroes(nums):
        zero_count = 0
        n = len(nums)
        
        for i in range(n):
            if nums[i] == 0:
                zero_count += 1
            else:
                nums[i - zero_count] = nums[i]
        
        for i in range(n - zero_count, n):
            nums[i] = 0
        print(nums)
moveZeroes([0,0,1])