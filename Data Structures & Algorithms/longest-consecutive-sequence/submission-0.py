class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        """
        Input: nums = [0,3,2,5,4,6,1,1]
        mp = {
            {0 : 1}, | res = 1
            {3 : 2}, | res = 1
            {2 : 5}, left = 2, right = 3 | res = 2
            {5 : 4}, | res = 2
            {4 : 4}, left = 2, right = 5 | res = 4
            {6 : 5}, left = 2, right = 6 | res = 5
            {1 : 6}, left = 0, right = 6 | res = 7
        } -> Output: 7

        [left ... num - 1] |  num  | [num + 1 ... right ]
        n          n     | n+m+1 |   m            m
        (num - 1) - left + 1 = n -> left = num - n = num - mp[num - 1]
        right - (num + 1) + 1 = m -> right = m + num = mp[num + 1] + num
        """
        mp = defaultdict(int)
        res = 0

        for num in nums:
            if not mp[num]:
                mp[num] = mp[num - 1] + mp[num + 1] + 1
                mp[num - mp[num - 1]] = mp[num]
                mp[num + mp[num + 1]] = mp[num]
                res = max(res, mp[num])

        return res