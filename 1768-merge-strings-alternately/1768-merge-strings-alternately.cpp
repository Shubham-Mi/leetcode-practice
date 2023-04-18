class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int ptr = 0;
        string ans = "";
        while (ptr < n && ptr < m) {
            ans.push_back(word1[ptr]);
            ans.push_back(word2[ptr]);
            ptr++;
        }
        if (ptr < n) ans = ans + word1.substr(ptr);
        if (ptr < m) ans = ans + word2.substr(ptr);
        return ans;
    }
};