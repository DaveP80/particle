# LeetCode No. 48 Rotate Image
# Rotate 2d Matrix by 90 degrees in place.
class Solution(object):
    def rotate(self, matrix):
        temp = zip(*matrix[::-1])
        for i,j in enumerate(temp):
            matrix[i] = list(j)
