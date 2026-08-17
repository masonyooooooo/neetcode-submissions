class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> seen;

        for (int i = 0; i < n; i++) {
            int need = target - nums[i];
            auto itr = seen.find(need);
            if (itr == seen.end())
                seen[nums[i]] = i;
            else
                return {seen[need], i};
        }
        return {};
    }
};
