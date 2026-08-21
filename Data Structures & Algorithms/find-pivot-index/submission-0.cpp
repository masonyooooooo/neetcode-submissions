class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int l = 0;
        int r = nums.size() - 1;
        int lsum = 0;
        int rsum = 0;
        
        // l == r is the potential pivot not included
        while (l < r) {
            if (lsum < rsum) {
                lsum += nums[l];
                l++;
            } else {
                rsum += nums[r];
                r--;
            }
        }

        if (lsum == rsum) {
            return l;
        }
        return -1;
    }
};