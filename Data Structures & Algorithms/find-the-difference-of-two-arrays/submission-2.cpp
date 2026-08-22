class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // First reaction: distinct -> set
        vector<int> res1, res2;
        unordered_set<int> s1, s2;
        for (int num: nums1) {
            s1.insert(num);
        }

        for (int num: nums2) {
            s2.insert(num);
        }

        for (int num: s1) {
            if (s2.find(num) == s2.end()) {
                res1.push_back(num);
            } else {
                s2.erase(num);
            }
        }

        for (int num: s2) {
            res2.push_back(num);
        }

        return{res1, res2};
    }
};