class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        unordered_map<int,int> mp;
        int i =0;
        for(auto x: elements){
            if(mp.find(x) == mp.end()) mp[x] = i;
            else mp[x] = min(mp[x],i);
            i++;
        }
        vector<int> ans(groups.size(),-1);
        for( i = 0;i<groups.size();i++){
            int n = groups[i];
            for(int j = 1;j*j<=n;j++){
                if(n%j==0){
                    if(mp.find(j) !=mp.end()) ans[i] = ans[i] == -1 ? mp[j] : min(mp[j],ans[i]); 
                    if(mp.find(n/j) != mp.end()) ans[i] = ans[i] == -1 ? mp[n/j] : min(mp[n/j],ans[i]); 
                } 
            }
        }

        return ans;
    }
};