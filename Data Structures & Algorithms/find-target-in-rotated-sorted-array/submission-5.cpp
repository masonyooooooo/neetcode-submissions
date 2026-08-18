class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        // Exact search: target in [left, right]
        // non-empty condition: check the final candidate
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // termination condition
            // Worst case: left == right == mid
            if (nums[mid] == target)
                return mid;

            // `mid` must not the candidate, kick out
            // If left half [left, mid] is sorted
            if (nums[left] < nums[mid]) {
                // target is in the sorted half
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                // target is in the unsorted half
                else {
                    left = mid + 1;
                }
            }

            // If right half [mid, right] is sorted
            else {
                // target is in the sorted half
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
