class Solution {
public:
    int dp(vector <vector <int>>& memo, vector<int>& nums, vector<int>& multipliers, int mul_idx, int num_idx, int n, int m) {
        if (mul_idx == m) return 0;
        if (memo[num_idx][mul_idx] != -1) return memo[num_idx][mul_idx];
        // Choose left value
        int left = multipliers[mul_idx] * nums[num_idx] + dp(memo, nums, multipliers, mul_idx + 1, num_idx + 1, n, m);
        // Choose right value
        int right = multipliers[mul_idx] * nums[n - 1 - (mul_idx - num_idx)] + dp(memo, nums, multipliers, mul_idx + 1, num_idx, n, m);
        memo[num_idx][mul_idx] = max(left, right);
        return memo[num_idx][mul_idx];
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector <vector <int>> memo(n, vector <int> (m, -1));
        return dp(memo, nums, multipliers, 0, 0, n, m);
    }
};