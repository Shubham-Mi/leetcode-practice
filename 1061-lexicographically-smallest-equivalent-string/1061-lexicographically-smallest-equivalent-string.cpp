class Solution {
    vector <int> root;
public:
    int findroot(int x) {
        if (root[x] != root[root[x]]) root[x] = findroot(root[x]);
        return root[x];
    }
    void performUnion(int a, int b) {
        int rootX = findroot(a);
        int rootY = findroot(b);
        if (rootX != rootY) {
            if (rootX < rootY) root[rootY] = rootX;
            else root[rootX] = rootY;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        root = vector <int> (26);
        for (int i=0; i<26; ++i) root[i] = i;
        for (int i=0; i<n; ++i) {
            performUnion(s1[i] - 'a', s2[i] - 'a');
        }
        string ans;
        for (char c: baseStr) ans += (char)(findroot(c - 'a') + 'a');
        return ans;
    }
};