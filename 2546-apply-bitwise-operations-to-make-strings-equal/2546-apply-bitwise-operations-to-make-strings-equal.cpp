class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int n = s.size();
        int zerozero = 0;
        int zeroone = 0;
        int onezero = 0;
        int oneone = 0;
        for (int i=0; i<n; ++i) {
            if (s[i] == target[i]) {
                if (s[i] == '0') zerozero++;
                else oneone++;
            } else {
                if (s[i] == '0') zeroone++;
                else onezero++;
            }
        }
        
        if (zeroone  + onezero == 0) return true;
        if (zeroone) {
            if (oneone + onezero == 0) return false;
            oneone++;
        }
        if (onezero) {
            if (oneone == 0) return false;
        }
        return true;
    }
};