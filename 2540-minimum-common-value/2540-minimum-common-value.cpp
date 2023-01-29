class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int p1 = 0, p2 = 0;
        while (p1 < n && p2 < m) {
            if (nums1[p1] == nums2[p2]) return nums1[p1];
            else if (nums1[p1] < nums2[p2]) p1++;
            else p2++;
        }
        return -1;
    }
};