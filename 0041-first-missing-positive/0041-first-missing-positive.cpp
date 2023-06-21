class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int> m;
        for(auto x: nums){
            m[x]++;
        }
        int mn=1, mx=0;
        for(auto x: m ){
            if(x.first<=0) continue;
            else {
                mn = min(mn,x.first);
                mx = max(mx,x.first);
            }
        }
        
        while(mn<mx){
            if(!m[mn]){
                return mn;
            }
            mn++;
        }

        return mx+1;

    
    }
};