class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector <int> indegree(n, 0);
        for (vector <int> edge: edges) {
            indegree[edge[1]]++;
        }
        vector <int> neededNodes;
        for (int i=0; i<n; ++i) {
            if (indegree[i] == 0) neededNodes.push_back(i);
        }
        return neededNodes;
    }
};