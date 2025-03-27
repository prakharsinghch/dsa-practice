class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> mp;
        int mx=INT_MIN,m;
        for(auto x: nums){
            mp[x]++;
            if(mp[x] > mx){
                mx = mp[x];
                m = x;
            }
        }
        int ans = -1;
        int c = 0;
        int n= nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i] == m) c++;
            int sub = mp[m]-c;
            if(c > (i+1)/2 && sub>(n-i-1)/2){
                ans = i;
                break;
            }
            if(mp[m] == c) break;
        }

        return ans;
    }
};