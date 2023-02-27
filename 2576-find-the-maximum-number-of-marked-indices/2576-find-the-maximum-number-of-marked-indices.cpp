class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = (n + 1)  / 2;
        while (j < n) {
            if (2 * nums[i] <= nums[j]) i++;
            j++;    
        }
        return i * 2;
    }
};