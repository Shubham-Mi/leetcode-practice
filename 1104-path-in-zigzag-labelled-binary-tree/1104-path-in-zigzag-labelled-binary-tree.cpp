class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector <int> ans;
        ans.push_back(label);
        int st = 1;
        while (st * 2 <= label) {
            st *= 2;
        }
        int curr = label;
        while (curr > 1) {
            curr /= 2;
            st /= 2;
            int val = (3 * st) - (curr) - 1;
            ans.push_back(val);
            curr = val;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};