#rotate array, take x elements from end and add to beginning.
def rotate( nums, k):
        for i in range(k):
            n=nums[len(nums)-1]
            nums.pop()
            nums.insert(0,n)
        return nums
print(rotate([1,2,3,6,4,3,7,9], 2))