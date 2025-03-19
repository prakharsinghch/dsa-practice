class Solution {
public:

    bool check(vector<int>& candies, long long k, int mid){
        long long x = 0 ; 
        for(auto y: candies){
            x+= y/mid;
        }

        return x >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        int mx = INT_MIN; 
        for(auto x: candies){
            sum+=x;
            mx = max(mx,x);
        }
        if(sum < k) return 0;
        int ans = 0 ;
        int l = 1,h = mx ;
        while(l<h){
            int mid  = (l+h+1)/2;
            if(check(candies,k,mid)){
                l = mid;
            }
            else h = mid-1;
        }
        return l;
    }
};