"""
Aug 24, 2026 

================================

Problem: Contains Duplicate
Given an integer array `nums`, return `true` if any value appears more than once in the array, otherwise return false.

================================

Approach: Hash Table

If there are duplicates, the size of set will be less than the list.

================================

Dry Run:

[1, 2, 3, 3] -> 4
{1, 2, 3} -> 3

3 < 4 -> True

================================

Complexity:
- Time: O(N)
- Space: O(N)

================================

Notes:



"""
class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums)) < len(nums)