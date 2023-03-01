class Solution {
public:
    void merge(vector <int>& nums, int l, int r, int mid) {
        int length1 = mid - l + 1;
        int length2 = r - mid;
        vector <int> temp1(length1);
        for (int i=0; i<length1; ++i) temp1[i] = nums[l + i];
        vector <int> temp2(length2);
        for (int i=0; i<length2; ++i) temp2[i] = nums[mid + 1 + i];
        int p1 = 0;
        int p2 = 0;
        int k = l;
        while (p1 < length1 && p2 < length2) {
            if (temp1[p1] < temp2[p2]) nums[k++] = temp1[p1++];
            else nums[k++] = temp2[p2++];
        }
        while (p1 < length1) {
            nums[k++] = temp1[p1++];
        }
        while (p2 < length2) {
            nums[k++] = temp2[p2++];
        }
    }
    void mergeSort(vector <int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, r, mid);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};