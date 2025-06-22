class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for(int i=0;i<s.size();i+=k){
            string s1 = s.substr(i,k);
            ans.push_back(s1);
        }
        if(ans.back().size() < k){
            string s1 = ans.back();
            ans.pop_back();
            while(s1.size()<k){
                s1+=fill;
            }
            ans.push_back(s1);
        }

        return ans;
    }
};