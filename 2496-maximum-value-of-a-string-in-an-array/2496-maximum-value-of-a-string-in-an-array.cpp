class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for (string s: strs) {
            int n = s.size();
            bool hasChars = false;
            int curr = 0;
            for (int i=0; i<n; ++i) {
                if (s[i] >= '0' && s[i] <= '9') {
                    curr = curr * 10 + (s[i] - '0');
                } else {
                    hasChars = true;
                    break;
                }
            }
            if (hasChars) ans = max(ans, n);
            else ans = max(ans, curr);
        }
        return ans;
    }
};