class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> stk;
        for (int i=0; i<n; ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') stk.push(s[i]);
            else if (s[i] == ')') {
                if (stk.empty() || stk.top() != '(')
                    return false;
                stk.pop();
            } else if (s[i] == '}') {
                if (stk.empty() || stk.top() != '{')
                    return false;
                stk.pop();
            } else if (s[i] == ']') {
                if (stk.empty() || stk.top() != '[')
                    return false;
                stk.pop();
            }
        }
        if (stk.empty())
            return true;
        return false;
    }
};