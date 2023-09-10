class Solution {
public:

    int m = 1e9+7;

    long long recr(int i){
        if( i == 1) return 1;

        long long ans =1;
        ans = (ans%m * (recr(i-1)*i*(2*i-1))%m)%m;

        return ans%m;
        
    }


    int countOrders(int n) {
        return recr(n);
    }
};