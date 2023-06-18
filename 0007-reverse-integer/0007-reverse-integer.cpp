class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        if(x<0) flag = true;
        long ans =0;
        while(x){
            int  i = x%10;
            x=x/10;
            ans = ans*10 +i;
        }

        // if(flag) return ans = ans*-1;
        if(ans > INT_MAX) return 0;
        if(ans < INT_MIN) return 0;
        return ans;
    }
};