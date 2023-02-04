class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;
        vector <int> cnt(26, 0);
        for (int i=0; i<n; ++i) {
            cnt[s1[i] - 'a']--;
            cnt[s2[i] - 'a']++;
        }
        bool found = false;
        for (int i=0; i<26; ++i) {
            if (cnt[i] != 0) {
                found = true;
                break;
            }
        }
        if (!found) return true;
        for (int i=n; i<m; ++i) {
            cnt[s2[i] - 'a']++;
            cnt[s2[i - n] - 'a']--;
            found = false;
            for (int i=0; i<26; ++i) {
                if (cnt[i] != 0) {
                    found = true;
                    break;
                }
            }
            
            if (!found) return true;
        }
        return false;
    }
};