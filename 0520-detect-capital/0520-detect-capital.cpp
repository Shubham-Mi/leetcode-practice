class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if (n == 1) return true;
        bool capital = (word[0] >= 'A' && word[0] <= 'Z');
        if (capital) {
            if (word[1] >= 'A' && word[1] <= 'Z') {
                for (char c: word) {
                    if (!(c >= 'A' && c <= 'Z')) return false;
                }
            } else {
                for (int i=1; i<n; ++i) {
                    char c = word[i];
                    if (!(c >= 'a' && c <= 'z')) return false;
                }
            }
        } else {
            for  (char c: word) {
                if (!(c >= 'a' && c <= 'z')) return false;
            }
        }
        return true;
    }
};