class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int, int> mp;
        int pairs = 0;
        long long ans = 0;
        int j = 0;
        for (int i=0; i<n; ++i) {
            mp[nums[i]]++;
            pairs += mp[nums[i]] - 1;
            if (pairs >= k) {
                ans = (1LL) * (ans + n - i);
                while (pairs >= k) {
                    mp[nums[j]]--;
                    pairs -= mp[nums[j]];
                    j++;
                    if (pairs >= k) ans = (1LL) * (ans + n - i);
                }
            }
        }
        return ans;
    }
};