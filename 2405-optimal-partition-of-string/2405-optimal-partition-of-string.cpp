class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int p1 = 0;
        unordered_set <char> st;
        int ans = 1;
        for (int i=0; i<n; ++i) {
            if (st.find(s[i]) != st.end()) {
                st.clear();
                ans++;
            }
            st.insert(s[i]);
        }
        return ans;
    }
};