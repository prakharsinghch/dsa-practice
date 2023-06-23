class Solution {
public:

    bool solve(vector<int>&piles,int h, int mid){
        int s = 0;
        for(auto x:piles){
            if(x%mid==0) h-=(x/mid);
            else h-=(x/mid)+1;

          
          if(h<0) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = INT_MIN;
        for(auto x: piles){
           
            high = max(x,high);
        }
        
        while(low<=high){
            int mid  = (low+high)/2;
            if(solve(piles,h,mid)){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};