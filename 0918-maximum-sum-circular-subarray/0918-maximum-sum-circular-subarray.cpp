class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total_sum = nums[0];
        int mx_sum = nums[0];
        int mx = nums[0];
        int mn_sum = nums[0];
        int mn = nums[0];
        for (int i=1; i<n; ++i) {
            int num = nums[i];
            total_sum += num;
            mx_sum = max(num, num + mx_sum);
            mx = max(mx, mx_sum);
            mn_sum = min(num, num + mn_sum);
            mn = min(mn, mn_sum);
        }
        if (mx > 0) return max(mx, total_sum - mn);
        return mx;
    }
};