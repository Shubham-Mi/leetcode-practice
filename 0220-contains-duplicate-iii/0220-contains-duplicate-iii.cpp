class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        set <int> s;
        for (int i=0; i<n; ++i) {
            if (i > indexDiff) s.erase(nums[i - indexDiff - 1]);
            auto ptr = s.lower_bound((long long)nums[i] - valueDiff);
            if (ptr != s.end() && *ptr - nums[i] <= valueDiff) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};