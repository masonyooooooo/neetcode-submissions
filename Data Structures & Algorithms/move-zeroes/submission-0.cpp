class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> res(nums.size());
        int n = 0;
        for (int num : nums) {
            if (num != 0) {
                res[n] = num;
                n++;
            }
        }
        nums = res;
    }
};