class Solution {
public:
    bool isValid(string s) {
        vector<int> stk;
        unordered_map<char, char> parenthesis {{')', '('}, {']', '['}, {'}', '{'}};
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{')
                stk.push_back(c);
            if (c == ')' || c == ']' || c == '}') {
                if (stk.empty() || stk.back() != parenthesis[c])
                    return false;
                else
                    stk.pop_back();
            }
        }
        if (!stk.empty())
            return false;

        return true;
    }
};
