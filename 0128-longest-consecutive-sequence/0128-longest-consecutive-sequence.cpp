class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> mp;
        int ans = 0;
        for (int i=0; i<n; ++i) {
            if (mp.find(nums[i]) == mp.end()) {
                int l = 0;
                int r = 0;
                if (mp.find(nums[i] - 1) != mp.end()) l = mp[nums[i] - 1];
                if (mp.find(nums[i] + 1) != mp.end()) r = mp[nums[i] + 1];
                mp[nums[i]] = l + r + 1;
                mp[nums[i] - l] = mp[nums[i]];
                mp[nums[i] + r] = mp[nums[i]];
                ans = max(ans, mp[nums[i]]);
            }
        }
        return ans;
    }
};