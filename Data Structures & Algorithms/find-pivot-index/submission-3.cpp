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

        // Two pass (Prefix Sum - one array)
        // Pass 1: Calculate prefix sum
        // Pass 2: check sum

        vector<int> lsum {0};

        for (int i = 1; i < nums.size(); i++) {
            lsum.push_back(lsum[i - 1] + nums[i - 1]);
        }

        int rsum = 0;

        for (int i = nums.size() - 1; i > -1; i--) {
            if (rsum == lsum[i])
                return i;
            rsum += nums[i];
        }

        return -1;

    }
};