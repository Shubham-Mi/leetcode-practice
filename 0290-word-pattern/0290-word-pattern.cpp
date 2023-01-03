class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        int m = s.size();
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;
        int j = 0;
        for (int i=0; i<n; ++i) {
            string curr = "";
            if (j >= m) return false;
            while (j < m && s[j] != ' ') {
                curr.push_back(s[j]);
                j++;
            }
            j++;
            if (mp.find(pattern[i]) != mp.end() && mp[pattern[i]] != curr) return false;
            if (mp2.find(curr) != mp2.end() && mp2[curr] != pattern[i]) return false;
            mp[pattern[i]] = curr;
            mp2[curr] = pattern[i];
        }
        if (j < m) return false;
        return true;
    }
};