class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for (int num: nums) ans = ans ^ num;
        return ans;
    }
};