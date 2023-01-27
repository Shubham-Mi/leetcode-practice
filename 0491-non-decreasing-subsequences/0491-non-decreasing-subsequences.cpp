class Solution {
    set <vector <int>> s;
public:
    void backtrack(vector <int>& nums, vector <vector <int>>& ans, vector <int>& curr, int n, int i) {
        if (i == n) {
            if (curr.size() > 1 && s.find(curr) == s.end()) {
                ans.push_back(curr);
                s.insert(curr);
            }
            return;
        }
        backtrack(nums, ans, curr, n, i + 1);
        if (curr.size() == 0 || curr.back() <= nums[i]) {
            curr.push_back(nums[i]);
            backtrack(nums, ans, curr, n, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector <vector <int>> ans;
        vector <int> curr;
        backtrack(nums, ans, curr, n, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};