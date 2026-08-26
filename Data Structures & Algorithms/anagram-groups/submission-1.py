class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # Space: O(mn) or O(n)
        # Time: O(n) iterations
        #       O(mlogm) + O(1)
        #       O(n)
        # Total time: O(mnlogm) < O((mn)^2)

        groups = {}

        for s in strs:
            sortedS = "".join(sorted(s))
            if sortedS not in groups.keys():
                groups[sortedS] = [s]
            else:
                groups[sortedS].append(s)

        return list(groups.values())

'''
Manual Test:

["act","pots","tops","cat","stop","hat"]

{
"act": ["act", "cat"], 
"opst": ["pots", "tops", "stop"], 
"aht": ["hat"]
}

[["act", "cat"],["pots", "tops", "stop"],["hat"]]

Manual Test for edge case:
[]
[]

[""]
[[""]]
'''