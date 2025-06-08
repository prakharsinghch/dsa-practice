class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> res;
        vector<int> ans;
        for(int i =1;i<=n;i++){
            res.push_back(to_string(i));
        }

        sort(res.begin(),res.end());
        for(auto x: res){
            ans.push_back(stoi(x));
        }

        return ans;
    }
};