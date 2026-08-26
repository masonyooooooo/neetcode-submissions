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
        res = nums[0]
        l, r = 0, len(nums) - 1

        while l <= r:
            if nums[l] < nums[r]:
                res = res = min(res, nums[l])
            m = l + (r - l) // 2
            res = min(res, nums[m])

            # sorted left half -> right half
            if nums[l] <= nums[m]:
                l = m + 1

            # sorted right half -> left half
            else:
                r = m - 1

        return res


