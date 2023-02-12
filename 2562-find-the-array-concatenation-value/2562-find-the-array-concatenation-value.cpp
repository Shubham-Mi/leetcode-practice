class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();
        long long int ans = 0;
        int p1 = 0, p2 = n - 1;
        while (p1 <= p2) {
            if (p1 == p2) {
                ans = 1LL * (ans + nums[p1]);
            } else {
                int temp = nums[p2];
                int mul = 1;
                while (temp) {
                    mul *= 10;
                    temp /= 10;
                }
                ans = (ans + 1LL * (nums[p1] * mul + nums[p2]));
            }
            p1++;
            p2--;
        }
        return ans;
    }
};