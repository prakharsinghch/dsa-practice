class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        vector<int> x,y;
        x = nums;
        int c1 = 0 ,c2 = 0;

        for(int i = 1 ; i < x.size();i++){
            if(x[i-1] != 1){
                x[i-1]*=-1;
                x[i]*=-1;
                c1++;
            }
        }
        if(x[x.size()-1] == 1 && c1<=k) return true;
        y = nums;
        c1 = 0 ;
        for(int i = 1 ; i < y.size();i++){
            if(y[i-1] != -1){
                y[i-1]*=-1;
                y[i]*=-1;
                c1++;
            }
        }

        if(y[y.size()-1] == -1 && c1<=k) return true;

        return false;
    }
};