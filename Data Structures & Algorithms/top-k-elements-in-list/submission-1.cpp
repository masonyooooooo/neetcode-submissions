class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        vector<pair<int, int>> pairs {};
        for (auto& p : counts) {
            pairs.push_back({p.second, p.first});
        }
        sort(pairs.rbegin(), pairs.rend());
        vector<int> result;
        for (int i = 0; i < k; i++)
            result.push_back(pairs[i].second);
        return result;
    }
};
