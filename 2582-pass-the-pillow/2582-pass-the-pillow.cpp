class Solution {
public:
    int passThePillow(int n, int time) {
        int count = time / (n - 1);
        int last = time % (n - 1);
        
        if (count % 2) {
            return n - last;
        } else {
            return 1 + last;
        }
    }
};