class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts: dict[int, int] = {}
        for num in nums:
            counts[num] = counts.get(num, 0) + 1

        pairs: list[tuple[int, int]] = []
        for num, count in counts.items():
            pairs.append((num, count))

        pairs.sort(key=lambda item: item[1], reverse=True)

        result = []

        for i in range(k):
            result.append(pairs[i][0])
        
        return result