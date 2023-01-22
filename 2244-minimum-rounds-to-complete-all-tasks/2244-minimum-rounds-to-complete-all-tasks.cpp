class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        unordered_map <int, int> freq;
        for (int num: tasks) {
            freq[num]++;
        }
        int ans = 0;
        for (auto task: freq) {
            if (task.second == 1) return -1;
            ans += task.second / 3;
            if (task.second % 3) ans++;
        }
        return ans;
    }
};