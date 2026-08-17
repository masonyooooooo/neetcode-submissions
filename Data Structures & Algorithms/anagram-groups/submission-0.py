class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        if len(strs) == 1:
            return [strs]
        
        groups: dict[set[str], list[str]] = {}

        for s in strs:
            groups[set(s)] = groups.get(set(s), list()) + [s]

        result = []
        for _, lstr in groups.items():
            result.append(lstr)

        return result
