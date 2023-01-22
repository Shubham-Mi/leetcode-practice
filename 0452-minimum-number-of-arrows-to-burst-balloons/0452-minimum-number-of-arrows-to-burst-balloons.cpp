class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int st = points[0][0];
        int ed = points[0][1];
        int count = 0;
        for (int i=0; i<n; ++i) {
            if (points[i][0] <= ed) {
                st = min(st, points[i][0])                                      ;
                ed = min(ed, points[i][1]);
            } else {
                count++;
                st = points[i][0];
                ed = points[i][1];
            }
        }
        count++;
        return count;
    }
};