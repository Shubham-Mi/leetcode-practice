struct Trie {
    int count = 0;;
    Trie* children[26] = {};
};

class Solution {
    Trie* root;
public:
    void insertWord(string s) {
        int m = s.size();
        Trie* curr = root;
        for (int i=0; i<m; ++i) {
            int nextVal = s[i] - 'a';
            if (!curr -> children[nextVal]) curr -> children[nextVal] = new Trie();
            curr = curr -> children[nextVal];
            curr -> count++;
        }
    }

    int prefixSum(string s) {
        int m = s.size();
        Trie* curr = root;
        int ans = 0;
        for (int i=0; i<m; ++i) {
            int nextVal = s[i] - 'a';
            curr = curr -> children[nextVal];
            ans += curr -> count;
        }
        return ans;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        root = new Trie();
        for (string word: words) {
            insertWord(word);
        }
        vector <int> ans;
        for (string word: words) {
            ans.push_back(prefixSum(word));
        }
        return ans;
    }
};