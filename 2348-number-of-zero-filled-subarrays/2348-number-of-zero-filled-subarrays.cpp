class Solution {
public:
    long long calculateNoOfSubarrays(int n) {
        return 1LL * n * (n + 1) / 2;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int ans = 0;
        int cnt = 0;
        for (int num: nums) {
            if (num == 0) cnt++;
            else {
                ans += calculateNoOfSubarrays(cnt);
                cnt = 0;
            }
        }
        ans += calculateNoOfSubarrays(cnt);
        return ans;
    }
};