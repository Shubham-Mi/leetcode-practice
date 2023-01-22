class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        while (targetX && targetY) {
            while (!(targetX % 2)) targetX /= 2;
            while (!(targetY % 2)) targetY /= 2;
            if (targetX > targetY) targetX -= targetY;
            else if (targetX < targetY) targetY -= targetX;
            else return targetX == 1;
        }
        return false;
    }
};