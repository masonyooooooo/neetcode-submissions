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

        // Two pass (Optimal - no array)
        // Pass 1: Calculate prefix sum
        // Pass 2: check sum

        int rsum = 0, lsum = 0;

        for (int i = nums.size() - 1; i > -1; i--) {
            rsum += nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            rsum -= nums[i];
            if (rsum == lsum)
                return i;
            lsum += nums[i];
        }

        return -1;
    }
};