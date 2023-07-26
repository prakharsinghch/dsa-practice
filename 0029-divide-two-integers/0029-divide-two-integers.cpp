class Solution {
public:
    int divide(long dividend, long divisor) {
        bool flag = false;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        int s = (dividend > 0 ) ^ (divisor > 0) == 0 ? 1 : -1;
        dividend = abs(dividend), divisor = abs(divisor);
        long long ans = 0;
        while(dividend >= divisor){
            long temp = divisor, mul = 1;
            while(temp << 1 <= dividend){
                temp<<=1;
                mul<<=1;
            }
            dividend -= temp;
            ans +=mul;
        }

   
        return ans*s;

        
    }
};