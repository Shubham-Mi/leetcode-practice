class Solution {
public:
    bool checkValue(vector <int>& piles, int n, int h, int val) {
        long long int count = 0;
        for (int pile: piles) {
            count += (pile / val);
            if (pile % val > 0) count++;
        }
        if (count <= h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = piles[0];
        for (int pile: piles) high = max(high, pile);
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (checkValue(piles, n, h, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};