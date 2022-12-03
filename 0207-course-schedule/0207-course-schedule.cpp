class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector <vector <int>> adj(numCourses);
        vector <int> indegree(numCourses, 0);
        for (int i=0; i<n; ++i) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue <int> q;
        for (int i=0; i<numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next: adj[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) q.push(next);
            }
        }
        for (int i=0; i<numCourses; ++i) {
            if (indegree[i] != 0) return false;
        }
        return true;
    }
};