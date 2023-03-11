class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map <char, unordered_set <string>> mp;
        for (string s: ideas) mp[s[0]].insert(s.substr(1, s.size() - 1));
        long long ans = 0;
        for (int i=0; i<26; ++i) {
            for (int j=i+1; j<26; ++j)  {
                int cnt = 0;
                for (string s: mp['a' + i]) {
                    if (mp['a' + j].find(s) != mp['a' + j].end()) cnt++;
                }

                ans += 1LL * (mp['a' + i].size() - cnt) * (mp['a' + j].size() - cnt) * 2;
            }
        }
        return ans;
    }
};