class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector <int> ans;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for (int next: adj[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) q.push(next);
            }
        }
        if (ans.size() != numCourses) return {};
        return ans;
    }
};