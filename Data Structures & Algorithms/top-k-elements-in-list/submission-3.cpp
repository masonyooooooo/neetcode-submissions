class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Bucket Sort
        unordered_map<int, int> counts;

        for (int num : nums)
            counts[num]++;

        vector<vector<int>> buckets(nums.size() + 1);

        for (auto& [num, freq] : counts) {
            buckets[freq].push_back(num);
        }

        vector<int> result;

        for (int freq = nums.size(); freq >= 1; freq--) {
            for (int num : buckets[freq]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
