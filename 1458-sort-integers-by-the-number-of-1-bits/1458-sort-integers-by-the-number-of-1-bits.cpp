class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        map<int, vector<int>> mp;
        for(auto x: arr){
            int count = 0;
            int n =x ;
            while(x){
                count += x&1;
                x>>=1;
            }
            mp[count].push_back(n); 
        }

        vector<int> ans;

        for(auto x: mp){
            for(auto i: x.second){
                ans.push_back(i);
            }
            // cout<<x.second<<endl;
        }

        return ans;
    }
};