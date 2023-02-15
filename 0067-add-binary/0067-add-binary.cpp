class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int sum = 0;
        int carry = 0;
        int ptr = 0;
        string ans;
        while (ptr < n or ptr < m or carry > 0) {
            sum = 0;
            if (ptr < n) sum += (a[ptr] - '0');
            if (ptr < m) sum += (b[ptr] - '0');
            sum += carry;
            carry = sum / 2;
            sum %= 2;
            ans.push_back('0' + sum);
            ptr++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};