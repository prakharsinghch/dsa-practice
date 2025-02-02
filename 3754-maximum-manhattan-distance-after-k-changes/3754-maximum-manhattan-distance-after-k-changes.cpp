class Solution {
public:
    int maxDistance(string s, int k) {
        int a=0,b=0,c=0,d=0;
        vector<int> ans;
        for(auto x: s){
            if(x == 'N') a++;
            if(x == 'S') b++;
            if(x == 'E') c++;
            if(x == 'W') d++;

            int i = min(a,b), j = max(a,b);
            int n = min(c,d), l = max(c,d);
            int z = min(n+i,k);

            ans.push_back(l+j-n-i + 2*z);            
        }   

        int mx = INT_MIN;
        for(auto x: ans) mx = max(x,mx);

        return mx;
    }
};