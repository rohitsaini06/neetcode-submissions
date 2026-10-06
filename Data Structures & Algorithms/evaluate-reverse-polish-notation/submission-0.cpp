class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string s : tokens) {
            if (s != "+" && s != "-" && s != "/" && s != "*") {
                stk.push(stoi(s));
            } else {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();

                if (s == "+") stk.push(b+a);
                else if (s == "-") stk.push(b-a);
                else if (s == "*") stk.push(b*a);
                else stk.push(b/a);
            }
        }
        return stk.top();
    }
};
