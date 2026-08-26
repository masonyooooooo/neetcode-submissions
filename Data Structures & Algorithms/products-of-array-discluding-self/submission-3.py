class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        """
        Space Optimization: 
            two vars: one left product and one right product of nums[i]

        Complexity:
            Time: O(n)
            Space: O(1)
        """

        res: list[int] = []
        lprod = rprod = 1

        for num in nums:
            rprod = rprod * num

        for num in nums:
            rprod /= num
            res.append(rprod * lprod)
            lprod *= rprod

        return res