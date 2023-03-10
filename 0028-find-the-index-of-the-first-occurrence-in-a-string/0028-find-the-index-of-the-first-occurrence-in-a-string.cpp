class Solution {
public:
    vector <int> calculateLps(string s) {
        int n = s.size();
        vector <int> lps(n, 0);
        int prev = 0;
        int i=1;
        while (i < n) {
            if (s[i] == s[prev]) {
                prev++;
                lps[i] = prev;
                i++;
            } else {
                if (prev == 0) i++;
                else prev = lps[prev - 1];
            }
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        int n = needle.size();
        vector <int> lps = calculateLps(needle + '$' + haystack);
        int m = lps.size();
        for (int i=n+1; i<m; ++i) {
            if (lps[i] == n) return i - n - n;
        }
        return -1;
    }
};