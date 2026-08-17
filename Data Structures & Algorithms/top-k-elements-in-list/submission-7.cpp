class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        vector<pair<int, int>> pairs {};
        for (auto& p : counts) {
            pairs.push_back(p);
        }
        sort(pairs.begin(), pairs.end(), [](pair<int, int> p1, pair<int, int> p2) 
                                            {
                                                return p1.second > p2.second;
                                            });
        vector<int> result;
        for (int i = 0; i < k; i++)
            result.push_back(pairs[i].first);
        return result;
    }
};
