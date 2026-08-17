class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        map<char, int> counts;

        for (char c : s) {
            auto itr = counts.find(c);
            if (itr == counts.end())
                counts[c] = 1;
            else
                itr -> second += 1;
        }

        for (char c : t) {
            auto itr = counts.find(c);
            if (itr == counts.end())
                return false;
            else
                itr -> second -= 1;
        }

        for (auto count : counts) {
            if (count.second != 0)
                return false;
        }

        return true;
    }
};
