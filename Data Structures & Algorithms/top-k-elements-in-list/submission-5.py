class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts: dict[int, int] = {}
        for num in nums:
            counts[num] = counts.get(num, 0) + 1

        pairs: list[tuple[int, int]] = []
        for num, count in counts.items():
            pairs.append((count, num))

        pairs.sort()

        result = []

        while len(result) < k:
            result.append(pairs.pop()[1])
        return result