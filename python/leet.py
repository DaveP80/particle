#Given an integer array nums, move all 0's to the end of it while 
# maintaining the relative order of the non-zero elements.
# Note that you must do this in-place without making a copy of the array.
def moveZeroes(nums):
        storage = []
        for n in nums:
            if n==0:
                storage.append(0)
                nums.remove(0)
        print(len(nums))
        nums += storage
        print(nums)
moveZeroes([0,0,1])