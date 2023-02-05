class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue <int> pq;
        for (int num: gifts) {
            pq.push(num);
        }
        while (!pq.empty() && k) {
            k--;
            int curr = pq.top();
            pq.pop();
            pq.push(sqrt(curr));
        }
        long long int ans = 0;
        while (!pq.empty()) {
            ans = 1LL * (ans + pq.top());
            pq.pop();
        }
        return ans;
    }
};