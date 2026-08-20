"""
Most obvious solution:
    The water is determined by maxLeft, maxRight, and height of current position.
    water[i] = min(maxLeft, maxRight) - height[i]
"""
class Solution:
    def trap(self, height: List[int]) -> int:
        maxLeft: list[int] = [0] * len(height)
        maxRight: list[int] = [0] * len(height)
        l, r = 1, len(height) - 2
        while l < len(height):
            maxLeft[l] = maxLeft[l - 1] if height[l - 1] < maxLeft[l - 1] else height[l - 1]
            maxRight[r] = maxRight[r + 1] if height[r + 1] < maxRight[r + 1] else height[r + 1]
            l, r = l + 1, r - 1

        water = 0
        for i in range(len(height)):
            water += max(min(maxLeft[i], maxRight[i]) - height[i], 0)

        return water
        