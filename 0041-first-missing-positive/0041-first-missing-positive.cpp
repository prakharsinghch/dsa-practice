class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int> m;
        for(auto x: nums){
            m[x]++;
        }
        
        for(int i=1;i<=nums.size()+1;i++){
            if(m[i] == 0) return i;
        }
        
        // while(mn<mx){
        //     if(!m[mn]){
        //         return mn;
        //     }
        //     mn++;
        // }

        return 1;

    
    }
};