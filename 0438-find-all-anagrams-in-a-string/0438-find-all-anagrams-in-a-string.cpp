class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector <int> count(26, 0);
        for (char c: p) count[c - 'a']++;
        vector <int> ans;
        for (int i=0; i<n; ++i) {
            count[s[i] - 'a']--;
            if (i >= m) count[s[i - m] - 'a']++;
            int cnt = 0;
            for (int i=0; i<26; ++i) {
                if (count[i] != 0) {
                    cnt++;
                    break;
                }
            }
            if (cnt == 0) ans.push_back(i - m + 1);
        }
        return ans;
    }
};