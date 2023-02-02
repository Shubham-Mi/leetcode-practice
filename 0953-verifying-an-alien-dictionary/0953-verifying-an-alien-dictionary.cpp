class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int m = words.size();
        unordered_map <char, int> mp;
        for (int i=0; i<26; ++i) mp[order[i]] = i;
        for (int i=1; i<m; ++i) {
            int s = words[i].size();
            int t = words[i - 1].size();
            int p1 = 0, p2 = 0;
            while (p1 < s && p2 < t && words[i][p1] == words[i - 1][p2]) {
                p1++;
                p2++;
            }
            if (p1 < s && p2 < t && mp[words[i][p1]] < mp[words[i - 1][p2]]) return false;
            else if (p1 == s && p2 < t) return false;
        }
        return true;
    }
};