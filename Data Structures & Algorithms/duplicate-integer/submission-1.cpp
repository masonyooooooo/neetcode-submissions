class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> nums_set {};
        for (int num : nums)
            nums_set.insert(num);
        if (nums.size() == nums_set.size())
            return false;
        return true;
    }
};