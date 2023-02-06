class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector <string> rows(numRows);
        int buffer = 1;
        int curr = 0;
        for (char c: s) {
            rows[curr].push_back(c);
            curr += buffer;
            if (curr == numRows - 1) buffer = -1;
            if (curr == 0) buffer = 1;
        }
        string ans;
        for (string row: rows) {
            ans += row;
        }
        return ans;
    }
};