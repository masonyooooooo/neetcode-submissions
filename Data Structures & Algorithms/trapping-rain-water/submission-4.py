"""
Optimized solution:
    The water is determined by maxLeft, maxRight, and height of current position.
    water[i] = min(maxLeft, maxRight) - height[i]

Optimization: How to get maxLeft and maxRight without extra pass?
    Two pointers: l and r
    Findings:
        - right pos has higher maxLeft
        - left pos has higher maxRight
    Solution:
        If l/r has lower maxLeft/maxRight, enought info to get water and move to next pos
"""

class Solution:
    def trap(self, height: List[int]) -> int:
        l, r = 1, len(height) - 2
        maxLeft, maxRight = height[0], height[-1]
        water = 0

        while l <= r:
            if maxLeft < maxRight:
                maxLeft = max(maxLeft, height[l - 1])
                water += max(0, maxLeft - height[l])
                l += 1
            else:
                maxRight = max(maxRight, height[r + 1])
                water += max(0, maxRight - height[r])
                r -= 1

        return water