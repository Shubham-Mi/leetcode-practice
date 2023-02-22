class Solution {
public:

    bool isPossible(vector <int>& weights, int n, int maxWeight, int days) {
        int count = 1;
        int sum = 0;
        for (int i=0; i<n; ++i) {
            sum += weights[i];
            if (sum > maxWeight) {
                count++;
                sum = weights[i];
            }
        }
        if (count <= days) return true;
        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = weights[0];
        int high = 0;
        for (int weight: weights) {
            low = max(low, weight);
            high += weight;
        }
        int ans = high;
        while (low <= high) {
            int mid = (low +  high) / 2;
            if (isPossible(weights, n, mid, days)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};