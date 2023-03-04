class Solution {
public:
    int splitNum(int num) {
        vector <int> arr;
        while (num) {
            arr.push_back(num % 10);
            num /= 10;
        }
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int n1 = 0;
        int n2 = 0;
        bool first = true;
        for (int curr: arr) {
            if (first) {
                n1 = n1 * 10 + curr;
            } else {
                n2 = n2 * 10 + curr;
            }
            first = !first;
        }
        return n1 + n2;
    }
};