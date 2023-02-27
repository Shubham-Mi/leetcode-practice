class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        long long rem = 0;
        vector <int> ans;
        for (int i=0; i<n; ++i) {
            rem = ((rem * 10) + word[i] - '0') % m;
            if (rem == 0) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};