class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Generic Slide Window Solution:
        int left = 0;
        int longest = 0;
        unordered_set<char> seen;

        for (int right = 0; right < s.length(); ++right) {
            while (seen.contains(s[right])) {
                seen.erase(s[left]);
                left += 1;
            }
            seen.insert(s[right]);
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};
