class Solution {
    int n;
    vector <long long int> values;
public:
    bool possible(int mx) {
        vector <long long int> nums = values;
        for (int i=n-1; i>0; --i) {
            if (nums[i] > mx) {
                nums[i - 1] += (nums[i] - mx);
            }
        }
        return nums[0] <= mx;
    }
    int minimizeArrayValue(vector<int>& nums) {
        n = nums.size();
        int low = 0;
        int high = nums[0];
        for (int i=0; i<n; ++i) {
            values.push_back((1LL) * nums[i]);
            high = max(high, nums[i]);
        }
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};