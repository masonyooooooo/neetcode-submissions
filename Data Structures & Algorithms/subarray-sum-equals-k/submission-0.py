class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        """
        Hash Map + Prefix Sum (like Two-Sum):
            Hash Map: preSum : num of preSum
            Assumpe: prefix sum of position `i` is `p`
            diff = p - k
            if diff == 0:
                res += 1 -> [0, i] is the only subarray ended at i
            if diff != 0: -> I still need to substract diff
                res += preSum[diff] -> num of subarraies whose sum is diff
        """

        res = 0
        curSum = 0
        preSum = {0 : 1}

        for num in nums:
            curSum += num
            diff = curSum - k

            res += preSum.get(diff, 0)
            preSum[curSum] = 1 + preSum.get(curSum, 0)

        return res
