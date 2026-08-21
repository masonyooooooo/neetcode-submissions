class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1, n2;
        vector<int> diff1, diff2;
        for (int num : nums1) {
            n1.insert(num);
        }

        for (int num : nums2) {
            n2.insert(num);
        }

        for (int num : n2) {
            if (n1.find(num) != n1.end()) {
                n1.erase(num);
            } else {
                diff2.push_back(num);
            }
        }

        for (auto& num : n1) {
            diff1.push_back(num);
        }

        return {diff1, diff2};
    }
};