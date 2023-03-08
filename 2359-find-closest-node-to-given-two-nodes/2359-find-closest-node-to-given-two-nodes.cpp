class Solution {
public:
    void findDistances(vector<int>& edges, int node, vector <int>& distances) {
        int curr = node;
        int dist = 0;
        while (curr != -1) {
            if (distances[curr] != -1) return;
            distances[curr] = dist;
            dist++;
            curr = edges[curr];
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector <int> distances1(n, -1);
        findDistances(edges, node1, distances1);
        vector <int> distances2(n, -1);
        findDistances(edges, node2, distances2);
        int ans = -1;
        int currDist = INT_MAX;
        for (int i=0; i<n; ++i) {
            if (distances1[i] != -1 && distances2[i] != -1) {
                if (max(distances1[i], distances2[i]) < currDist) {
                    currDist = max(distances1[i], distances2[i]);
                    ans = i;
                }
            }
        }
        return ans;
    }
};