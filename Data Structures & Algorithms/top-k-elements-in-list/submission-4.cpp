class Solution {
private:
    int partition(
        vector<pair<int, int>>& pairs,
        int left,
        int right
    ) {
        int pivotFreq = pairs[right].second;
        int store = left;

        for (int i = left; i < right; i++) {
            if (pairs[i].second < pivotFreq) {
                swap(pairs[i], pairs[store]);
                store++;
            }
        }

        swap(pairs[store], pairs[right]);

        return store;
    }

    void quickSelect(
        vector<pair<int, int>>& pairs,
        int left,
        int right,
        int target
    ) {
        while (left < right) {
            int pivot = partition(pairs, left, right);

            if (pivot == target) {
                return;
            }

            if (pivot < target) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;

        for (int num : nums) {
            counts[num]++;
        }

        vector<pair<int, int>> pairs;

        for (auto& [num, freq] : counts) {
            pairs.push_back({num, freq});
        }

        int m = pairs.size();

        // We partition ascending by frequency.
        // Therefore the largest k elements begin at index m - k.
        quickSelect(pairs, 0, m - 1, m - k);

        vector<int> result;

        for (int i = m - k; i < m; i++) {
            result.push_back(pairs[i].first);
        }

        return result;
    }
};