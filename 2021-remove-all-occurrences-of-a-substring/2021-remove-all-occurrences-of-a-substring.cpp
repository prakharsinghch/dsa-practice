class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.size();
        string ans = "";
        for(int i=0;i<s.size();i++){
            ans+=s[i];
            if(ans.size() >= n && ans.substr(ans.size()-n) == part){
                ans.erase(ans.size()-n);
            }
        }

        return ans;
    }
};