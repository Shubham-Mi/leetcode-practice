class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1) return trust.size() == 0 ? 1 : -1;
        int m = trust.size();
        unordered_map <int, vector <int>> mp;
        unordered_set <int> notJudge;;
        for (vector <int> trusts: trust) {
            mp[trusts[1]].push_back(trusts[0]);
            notJudge.insert(trusts[0]);
        }
        for (int i=1; i<=n; ++i) {
            if (mp.find(i) != mp.end() && mp[i].size() == n - 1 && notJudge.find(i) == notJudge.end()) return i;
        }
        return -1;
    }
};