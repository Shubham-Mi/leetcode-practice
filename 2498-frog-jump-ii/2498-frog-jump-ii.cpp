class Solution {
public:
    bool check(vector <int>& stones, int n, int mid) {
        vector <bool> visited(n, false);
        int curr = 0;
        int prv = 0;
        while (curr < n) {
            if (prv == n-1) break;
            while (curr + 1 < n && stones[curr + 1] - stones[prv] <= mid) {
                curr++;
            }
            while (curr != prv && visited[curr]) {
                curr--;
            }
            if (curr == prv) return false;
            visited[curr] = true;
            prv = curr;
        }
        while (curr >= 0) {
            if (prv == 0) break;
            while (curr - 1 >= 0 && stones[prv] - stones[curr - 1] <= mid) {
                curr--;
            }
            while (curr != prv && visited[curr]) {
                curr++;
            }
            if (curr == prv) return false;
            visited[curr] = true;
            prv = curr;
        }
        return true;
    }
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int low = 1;
        int high = stones[n - 1];
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(stones, n, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};