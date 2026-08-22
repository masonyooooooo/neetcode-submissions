class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // First reaction: distinct -> set
        vector<int> res1, res2;

        // TIP: Use iterator to initialize containers!
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

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