class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int prv = 0;
        for (int i=0; i<n; ++i) {
            int diff = arr[i] - prv - 1;
            if (k > diff) k -= diff;
            else return prv + k;
            prv = arr[i];
        }
        return prv + k;
    }
};