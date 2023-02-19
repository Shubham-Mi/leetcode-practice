class Solution {
public:
    int minMaxDifference(int num) {
        string curr = to_string(num);
        int n = curr.size();
        char digitToNine = 'A';
        char digitToZero = curr[0];
        int ptr = 0;
        while (ptr < n && curr[ptr] == '9') {
            ptr++;
        }
        if (ptr >= n) return num;
        digitToNine = curr[ptr];
        reverse(curr.begin(), curr.end());
        string ans = "";
        for (int i=0; i<n; ++i) {
            char a = curr[i];
            char b = curr[i];
            if (curr[i] == digitToNine) a = '9';
            if (curr[i] == digitToZero) b = '0';
            ans.push_back('0' + (a - b));
        }
        reverse(ans.begin(), ans.end());
        int res = stoi(ans);
        return res;
    }
};