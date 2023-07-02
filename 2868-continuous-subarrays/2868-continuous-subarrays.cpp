class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> m;
        int rear = 0;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
           m.insert(nums[i]);
           while(m.size() > 1 && *m.rbegin() - *m.begin() > 2){
               m.erase(m.find(nums[rear]));
               rear++;
           }
           ans+=i-rear+1;
        }

        return ans;
    }
};