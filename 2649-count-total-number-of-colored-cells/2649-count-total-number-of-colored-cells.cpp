class Solution {
public:
    long long coloredCells(int n) {
        long long x = pow(n,2);
        long long y = pow(n-1,2);
        return x+y;
    }
};