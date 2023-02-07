class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map <int, int> mp;
        int count = 0;
        int left = 0;
        int ans = 0;
        for (int i=0; i<n; ++i) {
            if (mp[fruits[i]] == 0) count++;
            mp[fruits[i]]++;
            while (count > 2) {
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0) count--;
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};