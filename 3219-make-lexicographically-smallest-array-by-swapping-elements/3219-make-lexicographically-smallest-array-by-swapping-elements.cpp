class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> copy = nums;
        map<int,queue<int>> levels;
        unordered_map<int,int> mp;
        sort(copy.begin(),copy.end());

        int curr = 0;
        levels[curr].push(copy[0]);
        mp[copy[0]] = 0;

        for(int i=1;i<copy.size();i++){
            if(copy[i] - copy[i-1] > limit){
                curr++;
            }
            levels[curr].push(copy[i]);
            mp[copy[i]] = curr;
        }

        for(int i = 0;i<nums.size();i++){
            int level = mp[nums[i]];
            nums[i] = levels[level].front();
            levels[level].pop();
        }   

        return nums;

    }
};