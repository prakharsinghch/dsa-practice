class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        long long x = pow(3,32);
        return x%n == 0 ? true : false;
    }
};