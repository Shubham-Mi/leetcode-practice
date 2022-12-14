class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = wordsDict.size();
        vector <int> list1;
        vector <int> list2;
        for (int i=0; i<n; ++i) {
            if (wordsDict[i] == word1) list1.push_back(i);
            if (wordsDict[i] == word2) list2.push_back(i);
        }
        int ans = INT_MAX;
        if (word1 != word2) {
            ans = abs(list1[0] - list2[0]);
            int p1 = 0, p2 = 0;
            while (p1 <list1.size() && p2 < list2.size()) {
                ans = min(ans, abs(list1[p1] - list2[p2]));
                if (list1[p1] < list2[p2]) p1++;
                else p2++;
            }
        } else {
            ans = list1[1] - list1[0];
            for (int i=1; i<list1.size(); ++i) ans = min(ans, list1[i] - list1[i - 1]);
        }
        return ans;
    }
};