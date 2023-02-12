class Solution {
public:
    int lowerPoint(vector<int>& nums, int n, long long int val) {
        int l = 0;
        int r = n - 1;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= val) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    int higherPoint(vector<int>& nums, int n, long long int val) {
        int l = 0;
        int r = n - 1;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] <= val) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long int ans = 0;
        for (int i=0; i<n; ++i) {
            int l = lowerPoint(nums, i, 1LL * (lower - nums[i]));
            int r = higherPoint(nums, i, 1LL * (upper - nums[i]));
            if (l != -1 && r != -1) {
                ans = 1LL * (ans + r - l + 1);
            }
        }
        return ans;
    }
};