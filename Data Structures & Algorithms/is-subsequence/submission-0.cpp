class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_set<char> target;

        for (char c : t) {
            target.insert(c);
        }

        for (char c : s) {
            if (target.find(c) == target.end()) {
                return false;
            }
        }

        return true;
    }
};