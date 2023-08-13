class Solution {
public:
    
   bool check(vector<int>& nums, int m, int x){
       int n = nums.size();
       set<int> s;
       for(int i=n-x-1;i>=0;i--){
           s.insert(nums[i+x]);
           auto j = s.lower_bound(nums[i]);

           if(abs(*j-nums[i]) <= m) return true;

            if(j != s.begin()){
                j--;
                if(abs(*j-nums[i])<= m) return true;
            }
       }

       return false;
   }
    
    int minAbsoluteDifference(vector<int>& nums, int x) {

        int mx = *max_element(nums.begin(),nums.end());
        int mn = *min_element(nums.begin(),nums.end());
        
        int l = 0, r = mx-mn;
        int res = 0;
        while(l<=r){
            int m =  l + (r - l) / 2;

            if(check(nums,m,x)){
                r = m-1;
                res = m;
            }
            else l = m+1;
        }

        return res;

    }
};