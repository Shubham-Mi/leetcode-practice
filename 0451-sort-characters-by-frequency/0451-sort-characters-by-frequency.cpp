class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map <char, int> mp;
        for (int i=0; i<n; ++i) mp[s[i]]++;
        priority_queue <pair <int, int>> pq;
        for (auto m: mp) pq.push({m.second, m.first});
        string ans = "";
        while (!pq.empty()) {
            char ch = pq.top().second;
            int count = pq.top().first;
            pq.pop();
            for (int i=0; i<count; ++i) ans.push_back(ch);
        }
        return ans;
    }
};