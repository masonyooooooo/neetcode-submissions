class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        """
        min-heap
        """
        counts = defaultdict(int)
        for num in nums:
            counts[num] += 1

        heap = []
        for num, count in counts.items():
            heapq.heappush(heap, (count, num))
            if len(heap) > k:
                heapq.heappop(heap)

        res = []
        for _, num in heap:
            res.append(num)

        return res
