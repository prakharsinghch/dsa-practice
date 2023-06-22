class Solution {
public:
    int minSteps(int n) {
        if (n == 1)
            return 0;

        int mi = 1e5;
        int minQ = 1;
        int curr = n;
        int res = 0;

        while(curr != 1){
            for(int j=1;j<=n;j++){
                if(curr%j == 0){
                    auto tmp = curr/j;
                    if(tmp != 1){
                        mi = min(mi,tmp);
                        minQ = j;
                    }
                }
            }
            res+=mi;
            curr = minQ;
            mi = 10000;
        }

        return res;
        
    }
};