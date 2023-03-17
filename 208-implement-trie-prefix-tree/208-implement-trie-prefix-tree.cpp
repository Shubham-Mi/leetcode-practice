class Trie {
public:
    vector <Trie*> children;
    bool isEnd;
    Trie() {
        children = vector <Trie*> (26, NULL);
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* root = this;
        for (char c: word) {
            int num = c - 'a';
            if (!root -> children[num]) root -> children[num] = new Trie();
            root = root -> children[num];
        }
        root -> isEnd = true;
    }
    bool search(string word) {
        Trie* root = this;
        for (char c: word) {
            int num = c - 'a';
            if (root -> children[num] == NULL) return false;
            root = root -> children[num];
        }
        if (root -> isEnd) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Trie* root = this;
        for (char c: prefix) {
            int num = c - 'a';
            if (root -> children[num] == NULL) return false;
            root = root -> children[num];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */