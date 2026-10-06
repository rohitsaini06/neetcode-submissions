class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (auto& chr : s) {
            if (chr == '[' || chr == '{' || chr == '(') stk.push(chr);
            else {
                if (stk.empty()) return false;

                if ((chr == ')' && stk.top() != '(') ||
                    (chr == '}' && stk.top() != '{') ||
                    (chr == ']' && stk.top() != '[')) return false;
                
                stk.pop();
            }
        }

        return stk.empty();
    }
};
