class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int, 128> last;
        last.fill(-1);

        int left = 0;
        int longest = 0;

        for (int right = 0; right < s.length(); ++right) {
            char c = s[right];
            // if c is duplicated, the pos of c is ahead of left.
            // -> last[c] > left -> left goes to the next -> left = last[c] + 1
            // if c is unique, the pos of c is behind of left.
            // -> last[c] < left -> left stay -> left = left
            left = max(left, last[c] + 1);
            // Update the new last pos of c:
            last[c] = right;
            // Update longest
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};
