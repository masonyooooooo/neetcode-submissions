class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            if (counts.contains(num))
                counts[num]++;
            else
                counts[num] = 1;
        }
        vector<int> result {};
        for (auto& p : counts) {
            if (p.second >= k)
                result.push_back(p.first);
        }
        return result;
    }
};
