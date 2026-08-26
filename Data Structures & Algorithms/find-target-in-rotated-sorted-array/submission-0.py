class Solution:
    def search(self, nums: List[int], target: int) -> int:
        """
        - Relation: sorted
        - Complexity: O(log n) time
        Binary Search!
        """
        l, r = 0, len(nums) - 1

        while l <= r: # The final position is possible candidate
            m = l + (r - l) // 2 # Prevent overflow
            # nums[m] is checked, no check again
            if nums[m] == target:
                return m
            
            # 1. Left half is sorted
            # [Q] `<` or `<=`? [A] no double check, so `<`
            if nums[l] < nums[m]:
                # target in the sorted part
                if target < nums[m] and nums[l] <= target:
                    r = m - 1
                else:
                    l = m + 1

            # 2. Right half is sorted
            else:
                # target in the sorted part
                if target > nums[m] and nums[r] >= target:
                    l = m + 1
                else:
                    r = m - 1

        return -1
            