class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack <char> stack;
        for (int i=0; i<n; ++i) {
            if (s[i] == ']') {
                string curr = "";
                while (stack.top() != '[') {
                    curr += stack.top();
                    stack.pop();
                }
                stack.pop();
                int base = 1;
                int k = 0;
                while (!stack.empty() && isdigit(stack.top())) {
                    k = k + (stack.top() - '0') * base;
                    stack.pop();
                    base *= 10;
                }
                int m = curr.size();
                while (k > 0) {
                    for (int j=m-1; j>=0; --j) {
                        stack.push(curr[j]);
                    }
                    k--;
                }
            }
            else {
                stack.push(s[i]);
            }
        }
        string result;
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
    }
};