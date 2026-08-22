class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Two Pointers: one for s and one for t
        // Not match: t moves to the next
        // Match: both move to the next
        // Stop: s or t reaches to the end
        // Check: All s is matched
        int i = 0, j = 0;

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        if (i == s.size())
            return true;

        return false;
    }
};