class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        """
        Space Optimization: 
            two vars: one left product and one right product of nums[i]

        Complexity:
            Time: O(n)
            Space: O(1)
        """

        res: list[int] = [0] * len(nums)
        lprod = rprod = 1
        zeros = 0

        for i in range(len(nums) - 1, 1, -1):
            if num:
                rprod = rprod * num
            else:
                zeros += 1

        if zeros > 1:
            return res

        for i, num in enumerate(nums):
            if zeros == 1:
                res[i] = 0 if num else rprod * lprod
            rprod = rprod / num if num else rprod
            lprod = lprod * num if num else lprod

        return res