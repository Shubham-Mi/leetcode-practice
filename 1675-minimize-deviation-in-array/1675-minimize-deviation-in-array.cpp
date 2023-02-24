class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        priority_queue <int, vector <int>, less <int>> pq;
        int mn = INT_MAX;
        for (int i=0; i<n; ++i) {
            if (nums[i] % 2) nums[i] *= 2;
            mn = min(mn, nums[i]);
            pq.push(nums[i]);
        }
        int ans = INT_MAX;
        while (pq.top() % 2 == 0) {
            int curr = pq.top();
            pq.pop();
            ans = min(ans, curr - mn);
            mn = min(mn, curr / 2);
            pq.push(curr / 2);
        }
        return min(ans, pq.top() - mn);
    }
};