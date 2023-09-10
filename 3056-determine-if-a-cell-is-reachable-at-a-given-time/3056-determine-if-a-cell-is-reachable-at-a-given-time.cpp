class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && fy == sy && t==1) return false;
        int x = 0;
        int y = 0;
        x = abs(fx-sx);
        y = abs(sy-fy);

        int z = x-y;
        if(z <= 0) return y<=t;

        return y+z<= t;
    }
};