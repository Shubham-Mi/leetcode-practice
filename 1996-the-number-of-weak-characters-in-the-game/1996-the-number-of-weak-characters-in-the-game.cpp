class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        sort(properties.begin(), properties.end());
        vector <int> defenceMax(n, 0);
        int ptr = n-1;
        int mx = 0;
        while (ptr >= 0 && properties[ptr][0] == properties[n - 1][0]) {
            defenceMax[ptr] = 0;
            mx = max(mx, properties[ptr][1]);
            ptr--;
        }
        for (int i=ptr; i>=0; --i) {
            if (properties[i][0] == properties[i + 1][0]) defenceMax[i] = defenceMax[i + 1];
            else defenceMax[i] = mx;
            mx = max(mx, properties[i][1]);
        }
        int ans = 0;
        for (int i=0; i<n; ++i) {
            if (properties[i][1] < defenceMax[i]) ans++;
        }
        return ans;
    }
};