class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        int m = s.size();
        int ans = 0;
        for (int i=0; i<m; ++i) {
            int curr = s[i] - '0';
            if (i % 2 == 0) ans += curr;
            else ans -= curr;
        }
        return ans;
    }
};