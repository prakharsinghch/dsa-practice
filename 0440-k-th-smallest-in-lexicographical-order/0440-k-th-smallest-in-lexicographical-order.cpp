class Solution {
public:

    int check(long a, long b, long n){
        int g = 0;

        while(a<= n){
            g += min(n+1,b)-a;
            a*=10;
            b*=10;
        }

        return g;
    }

    int findKthNumber(int n, int k) {
        long num =1;
        for(int i=1;i<k;){
            int req = check(num,num+1,n);
            if(i+req <= k){
                i+=req;
                num++;
            }
            else{
                i++;
                num*=10;
            }
        }
      return num;
    }
};
