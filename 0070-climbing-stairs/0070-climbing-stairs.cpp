class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        int a = 1;
        int b = 2;
        for (int i=3; i<=n; ++i) {
            int curr = a + b;
            a = b;
            b = curr;
        }
        return b;
    }
};