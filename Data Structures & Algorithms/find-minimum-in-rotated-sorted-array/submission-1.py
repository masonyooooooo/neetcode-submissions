class Solution:
    def findMin(self, nums: List[int]) -> int:
        """
        O(logn) solution for sorted array -> binary search

        Where can minimum element can reside?
        1. No Rotation:
            nums[0] < nums[-1] -> min = 0
        2. Rotated: nums[min] < nums[min - 1]
            2.1 [l, m]
            2.2 [m, r]
        """
        if len(nums) == 0:
            return -1
        if len(nums) == 1:
            return nums[0]
        if nums[0] < nums[-1]:
            return nums[0]
        l, r = 0, len(nums) - 1

        while l <= r:
            m = l + (r - l) // 2
            if nums[m] < nums[m - 1]:
                return nums[m]

            # sorted left half -> right half
            if nums[l] <= nums[m]:
                l = m + 1

            # sorted right half -> left half
            else:
                r = m - 1

        return -r


