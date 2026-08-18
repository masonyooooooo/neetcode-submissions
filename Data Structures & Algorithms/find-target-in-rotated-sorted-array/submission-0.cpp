/**
 * 1. length-n sorted array (asending order)
 * 2. rotated 1~n times: n times -> unchanged
 * 3. all elements are unique
 * 4. O(log n) solution
 * Given: rotated sorted array ``nums`` and an ``target``.
 * Find: index of ``target`` within ``nums``.
 */

 /**
  * O(log n) Solution: bineary search vriation
  * `[3, 4, 5, 1, 2]` & `4` -> first half
  * `[3, 4, 5, 1, 2]` $ `1` -> second half
  * `[4, 5, 1, 2, 3]` $
  */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                if (nums[left] == target) {
                    return left;
                } else if (nums[left] < target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[right] == target) {
                    return right;
                } else if (nums[right] > target) {
                    left = mid + 1;
                } else {
                    right = mid -1;
                }
            }

        }
        return -1;
    }
};
