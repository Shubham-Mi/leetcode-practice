class Solution {
public:
    int maxProfit(vector<int>& A) {
        int mn = A[0];
        int ans = 0;
        for (int price: A) {
            mn = min(mn, price);
            ans = max(ans, price - mn);
        }
        return ans;
    }
};