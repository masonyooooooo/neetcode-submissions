class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // First reaction: two pointers
        // One at the left and one at the right.

        // Simplest solution: Two pass
        // Pass 1:
        //      left -> right: left prefix sum
        //      right -> left: right prefix sum
        // Pass 2: check two sums

        vector<int> lsum(nums.size());
        vector<int> rsum(nums.size());
        int l = 1, r = nums.size() - 2;

        while (l < nums.size()) {
            lsum[l] = lsum[l - 1] + nums[l - 1];
            rsum[r] = rsum[r + 1] + nums[r + 1];
            l++;
            r--;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (lsum[i] == rsum[i])
                return i;
        }

        return -1;
    }
};