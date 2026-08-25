"""
Aug 24, 2026 

================================

Problem: Valid Anagram

Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

Two strings are anagrams if they contain the same characters, with each character appearing the same number of times, regardless of order.

Input: s = "racecar", t = "carrace"

Output: true

================================

Approach: Hash Map

Get the frequency statistics of one string, then compare with the another one.

================================

Dry Run:

Input: s = "jar", t = "jam"

count_s: {"j": 1 - 1, "a": 1 - 1, "r", 1} "m" not in count_s

================================

Complexity:
- Time: 
    - Traverse `s`: O(n)
    - Insert one char in map: O(log n)
    - Traverse `t`: O(m)
    - Find and decrease: O(log n)
    - Check the map: O(n)
    - Overall: O((m+n)log n)
- Space: O(n) for map

================================

Notes:



"""
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        counts = {}
        for c in s:
            counts[c] = 1 + counts.get(c, 0)

        for c in t:
            if c not in counts.keys():
                return False
            counts[c] -= 1

        for _, value in counts.items():
            if value != 0:
                return False

        return True
        