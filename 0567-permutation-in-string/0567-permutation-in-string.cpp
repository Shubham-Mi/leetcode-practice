class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector <int> count(26, 0);
        for (char c: s1) count[c - 'a']--;
        for (int i=0; i<m; ++i) {
            count[s2[i] - 'a']++;
            if (i >= n) count[s2[i - n] - 'a']--;
            bool found = false;
            for (int num: count) {
                if (num != 0) {
                    found = true;
                    break;
                }
            }
            if (!found) return true;
        }
        return false;
    }
};