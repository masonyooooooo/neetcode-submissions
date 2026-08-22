class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // CAUTION! Leftmost!

        // First reaction: two pointers
        // One at the left and one at the right.

        // Simplest solution: Two pass
        // Pass 1:
        //      left -> right: left prefix sum
        //      right -> left: right prefix sum
        // Pass 2: check two sums

        // Two pass (Prefix Sum - one array)
        // Pass 1: Calculate prefix sum
        // Pass 2: check sum

        vector<int> rsum(nums.size());

        for (int i = nums.size() - 2; i > -1; i--) {
            rsum[i] = rsum[i + 1] + nums[i + 1];
        }

        int lsum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (lsum == rsum[i])
                return i;
            lsum += nums[i];
        }

        return -1;

    }
};