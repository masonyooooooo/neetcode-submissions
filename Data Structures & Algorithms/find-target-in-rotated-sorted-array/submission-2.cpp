/**
 * 1. length-n sorted array (asending order)
 * 2. rotated 1~n times: n times -> unchanged
 * 3. all elements are unique
 * 4. O(log n) solution
 * Given: rotated sorted array ``nums`` and an ``target``.
 * Find: index of ``target`` within ``nums``.
 */

 /**
  * O(log n) Solution: bineary search variation
  * `[3, 4, 5, 1, 2]` & `4` -> first half
  * `[3, 4, 5, 1, 2]` $ `1` -> second half
  * `[4, 5, 1, 2, 3]` $
  */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            // Prevent overflow
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } 
            
            // Left half [left, mid] is sorted
            if (nums[left] <= nums[mid]) {
                // Is target inside the sorted left half?
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            // Otherwise right half [mid, right] is sorted
            else {
                // Is target inside the sorted right half?
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
