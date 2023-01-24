class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int ans = 0;
        for (int num: nums) {
            ans += num;
            while (num) {
                ans -= num % 10;
                num /= 10;
            }
        }
        return abs(ans);
    }
};