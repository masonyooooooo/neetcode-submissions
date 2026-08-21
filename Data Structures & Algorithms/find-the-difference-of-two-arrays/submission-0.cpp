class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> n1;
        vector<int> diff1, diff2;
        for (int num : nums1) {
            n1[num] = 0;
        }

        for (int num : nums2) {
            if (n1.find(num) != n1.end()) {
                n1[num]--;
            } else {
                diff2.push_back(num);
            }
        }

        for (auto& num : n1) {
            if (num.second == 0)
                diff1.push_back(num.first);
        }

        return {diff1, diff2};
    }
};