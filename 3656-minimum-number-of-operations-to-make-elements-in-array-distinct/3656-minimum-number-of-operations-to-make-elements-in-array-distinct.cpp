class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0,temp;

        while(true){
            unordered_map<int,int> mp;
            temp = 0;
            for(auto x: nums){
                mp[x]++;
                if(mp[x] == 2) temp++;
            }
            if(temp == 0) break;
            nums.erase(nums.begin(),nums.begin() + min(3,(int)nums.size()));
            cnt++;
        }   

        return cnt;
    }
};