class Solution {
public:

    bool check(vector<int>& nums, int m, int p){
        int c = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] - nums[i-1] <= m){
                c++;
                i++;
            }
           
        }

        return c>=p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int l = 0, h = nums[nums.size()-1]-nums[0];

        while(l<h){
            int m = (l+h)/2;
            if(check(nums,m,p)){
                h = m;
            }
            else l = m+1;
        }

        return l;

    }
};