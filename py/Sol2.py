# LeetCode No.2845 Count of Interesting subarrays
from typing import List
from collections import defaultdict
class Solution:
    def countInterestingSubarrays(self, nums: List[int], m: int, k: int) -> int:
        ct=0
        dct=defaultdict(int)
        dct[0]=1
        ans=0
        for n in nums:
            if n%m==k:
                ct+=1
            if ct==m:
                ct=0       
            r=ct-k if ct>=k else ct-k+m
            ans+=dct[r]
            dct[ct]+=1
        return ans 
solution = Solution()
ans = solution.countInterestingSubarrays([3, 1, 9, 6], 3, 0)
print(ans)