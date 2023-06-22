class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long ans=1;
        int c =0;
        bool flag = false;
        for(auto x: nums){
            if(x == 0) {
                flag = true;
                c++;
            }
            else ans*=x;
        }
        vector<int> res;
        for(auto x: nums){
            if(flag){
                if(x==0 && c<2) res.push_back(ans);
                else res.push_back(0);
            }
            else{
                res.push_back(ans/x);
            }
        }

        return res;

    }

};