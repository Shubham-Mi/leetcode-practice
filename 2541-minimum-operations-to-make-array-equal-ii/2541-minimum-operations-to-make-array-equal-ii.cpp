class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        if (k == 0) {
            for (int i=0; i<n; ++i) {
                if (nums1[i] != nums2[i]) return -1;
            }
            return 0;
        }
        
        long long int decrease = 0;
        long long int increase = 0;
        for (int i=0; i<n; ++i) {
            if (nums1[i] < nums2[i]) {
                int diff = nums2[i] - nums1[i];
                if (diff % k != 0) return -1;
                increase += (1LL) * (diff / k);
            } else if (nums1[i] > nums2[i]) {
                int diff = nums1[i] - nums2[i];
                if (diff % k != 0) return -1;
                decrease += (1LL) * (diff / k);
            }
        }
        
        if (increase != decrease) return -1;
        return increase;
    }
};