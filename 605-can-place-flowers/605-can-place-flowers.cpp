class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        for (int i=0; i<m && n>0; ++i) {
            if (flowerbed[i] == 0) {
                if (i && flowerbed[i - 1] == 1) continue;
                if (i < m - 1 && flowerbed[i + 1] == 1) continue;
                flowerbed[i] = 1;
                n--;
            }
        }
        return n == 0;
    }
};