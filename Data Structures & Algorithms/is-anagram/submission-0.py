class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        counts: dict[str, int] = {}

        for ch in s:
            counts[ch] = counts.get(ch, 0) + 1

        for ch in t:
            counts[ch] = counts.get(ch, 0) - 1

        for _, count in counts.items():
            if count != 0:
                return False

        return True