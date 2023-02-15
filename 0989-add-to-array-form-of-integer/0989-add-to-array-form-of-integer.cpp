class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        reverse(num.begin(), num.end());
        int carry = 0;
        for (int i=0; i<n; ++i) {
            int sum = carry;
            sum += (k % 10);
            k /= 10;
            sum += num[i];
            carry = sum / 10;
            num[i] = sum % 10;
        }
        while (k || carry) {
            int sum = carry;
            sum += (k % 10);
            k /= 10;
            carry = sum / 10;
            num.push_back(sum % 10);
        }
        reverse(num.begin(), num.end());
        return num;
    }
};