class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = INT_MAX,n2 = INT_MIN;
        int c1 =0, c2=0;
               for(auto x:nums)
        {
            if(x==n1) c1++;
            else if(x==n2) c2++;
            else if(c1 == 0)
            {
                n1=x;
                c1++;
            }
            else if(c2 == 0)
            {
                n2 =x ;
                c2++;
            }
           
            else {
                c1--;
                c2--;
            }
        }        
        vector<int> ans;
        c1 = 0, c2= 0;
        
        for(auto x: nums){
            if(x == n1) c1++;
            else if(x == n2) c2++; 
        }
        int c = nums.size()/3;
        if(c1 > c ) ans.push_back(n1);
        if(c2 > c ) ans.push_back(n2);

      
        return ans;
    }
};