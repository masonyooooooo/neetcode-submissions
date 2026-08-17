class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        needs: dict[int, int] = {}

        for i in range(n):
            need = target - nums[i]
            if need in needs:
                return [needs[need], i]
            else:
                needs[nums[i]] = i
            
        return []