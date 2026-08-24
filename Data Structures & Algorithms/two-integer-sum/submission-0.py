class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen: dict[int, int] = {}
        for i in range(len(nums)):
            need = target - nums[i]
            if need in seen.keys():
                return [seen[need], i]
            else:
                seen[nums[i]] = i

        return []
        