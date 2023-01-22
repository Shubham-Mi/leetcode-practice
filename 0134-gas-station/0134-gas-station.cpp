class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int l = 0;
        int r = n - 1;
        int curr = gas[r] - cost[r];
        while (l < r) {
            if (curr < 0) {
                r--;
                curr += gas[r] - cost[r];
            } else {
                curr += gas[l] - cost[l];
                l++;
            }
        }
        if (curr < 0) return -1;
        return r;
    }
};