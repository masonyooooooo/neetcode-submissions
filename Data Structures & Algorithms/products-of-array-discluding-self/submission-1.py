class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        """
        Simplest method: 
            two lists: one left product and one right product of nums[i]

        Complexity:
            Time: O(n)
            Space: O(n)
        """

        res: list[int] = []
        lprod: list[int] = [1] * len(nums)
        rprod: list[int] = [1] * len(nums)

        l, r = 1, len(nums) - 2

        while l < len(nums):
            lprod[l] = lprod[l - 1] * nums[l - 1]
            rprod[r] = rprod[r + 1] * nums[r + 1]
            l += 1
            r -= 1

        for i in range(len(nums)):
            res.push_back(lprod[i] * rprod[i])

        return res