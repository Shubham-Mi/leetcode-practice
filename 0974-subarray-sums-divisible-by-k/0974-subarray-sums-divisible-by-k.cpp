class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        mp[0] = 1;
        int ans = 0;
        int sum = 0;
        for (int num: nums) {
            sum = (sum + num % k + k) % k;
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};