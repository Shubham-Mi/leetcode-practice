class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mid % 2 == 0 && mid < n - 1 && nums[mid] == nums[mid + 1]) low = mid + 1;
            else if (mid % 2 == 0 && mid > 0 && nums[mid] == nums[mid - 1]) high = mid - 1;
            else if (mid % 2 == 1 && mid > 0 && nums[mid] == nums[mid - 1]) low = mid + 1;
            else if (mid % 2 == 1 && mid < n - 1 && nums[mid] == nums[mid + 1]) high = mid - 1;
            else return nums[mid];
        }
        return nums[low];
    }
};