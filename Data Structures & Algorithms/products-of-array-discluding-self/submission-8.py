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
        lprod = 1
        rprod = 1
        zeros = 0

        for num in nums:
            if num:
                rprod = rprod * num
            else:
                zeros += 1

        if zeros > 1:
            return res

        for i in range(len(nums)):
            if zeros == 1:
                res[i] = 0 if nums[i] else rprod * lprod
                continue
            rprod //= nums[i]
            res[i] = rprod * lprod
            lprod *= nums[i]

        return res