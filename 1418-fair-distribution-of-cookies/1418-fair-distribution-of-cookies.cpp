class Solution {
public:

    bool check(int m, vector<int>& cookies, int k){
        int c = 0;
        int sum = 0;
        for(auto x: cookies){
            sum+=x;
            if(sum>m){
                c++;
                sum=x;
            }
        }
        c++;
        return c<=k;
    }

    int findMin(vector<int>& cookies, int k){
        int left = 0;
        int right = 0;
        for(auto x: cookies) {
            right+=x;
            left= max(left,x);
        }

        int res = right;

        while(left <= right){
            int mid = left + (right-left)/2;
            if(check(mid,cookies,k)){
                res = mid;
                right = mid-1;
            }
            else left = mid+1;
        }
        return res;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX;
        sort(cookies.begin(), cookies.end());
        do{
            ans = min(ans, findMin(cookies,k));
        }while(next_permutation(cookies.begin(),cookies.end()));

        return ans;

    }
};