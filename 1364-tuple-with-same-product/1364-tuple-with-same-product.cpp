class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        for(auto x: mp){
            if(x.second > 1){
                ans+=(x.second)*(x.second-1)*4;
            }
        }
        return ans;
    }

};