class Solution {
public:
    int shortestWay(string source, string target) {
        int n = source.size();
        int m = target.size();
        unordered_map <char, vector <int>> mp;
        for (int i=0; i<n; ++i) mp[source[i]].push_back(i);
        int prv = -1;
        int ans = 0;
        for (int i=0; i<m; ++i) {
            if (mp.find(target[i]) == mp.end()) return -1;
            vector <int> curr = mp[target[i]];
            int pos = upper_bound(curr.begin(), curr.end(), prv) - curr.begin();
            if (pos == curr.size()) {
                ans++;
                prv = curr[0];
            } else {
                prv = curr[pos];
            }
        }
        ans++;
        return ans;
    }
};