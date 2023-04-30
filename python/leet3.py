# Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
# Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
def twoSum(numbers: list, target: int):
    for n in range(len(numbers)):
        z = numbers[n+1:][::-1]
        for i in range(len(z)):
            if numbers[n] + z[i] == target:
                print(n, len(numbers)-i-1)
twoSum([12,13,23,28,43,44,59,60,61,68,70,86,88,92,124,125,136,168,173,173,180,199,212,221,227,230,277,282,306,314,316,321,325,328,336,337,363,365,368,370,370,371,375,384,387,394], 542)

# Fastest Solution
def twoSumAlt(numbers: list[int], target: int) -> list[int]:
    seen = {}
    for i, num in enumerate(numbers):
        complement = target - num
        if complement in seen:
            return [seen[complement]+1, i+1]
        seen[num] = i
print(twoSumAlt([8,4,33,7,388,54,46], 40))