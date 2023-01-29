class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(begin(score), end(score), [&k](const vector<int> &o1, const vector<int> &o2) {
            return (o1[k] > o2[k]);
        });
        return score;
    }
};