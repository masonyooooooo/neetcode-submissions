class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res1 = defaultdict(list)
        for i in strs:
            res1[tuple(sorted(i))].append(i)
        
        res = []
        for key, value in res1.items():
            res.append(value)
        return res
