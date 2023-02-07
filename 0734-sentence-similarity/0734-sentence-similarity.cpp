class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int n = sentence1.size();
        if (sentence2.size() != n) return false;
        unordered_map <string, unordered_set <string>> mp;
        for (vector <string> pairs: similarPairs) {
            mp[pairs[0]].insert(pairs[1]);
            mp[pairs[1]].insert(pairs[0]);
        }
        for (int i=0; i<n; ++i) {
            if (sentence1[i] != sentence2[i]) {
                if (mp[sentence1[i]].find(sentence2[i]) == mp[sentence1[i]].end() && mp[sentence2[i]].find(sentence1[i]) == mp[sentence2[i]].end())
                    return false;
            }
        }
        return true;
    }
};