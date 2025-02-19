class Solution {
public:

    void recr(int len,string s,vector<string>& v,string& ans,int n){
        if(len == n){
            v.push_back(ans);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(len == 0 || ans.back() != s[i]){
                ans+=s[i];
                recr(len+1,s,v,ans,n);
                ans = ans.substr(0,ans.size()-1);
            }
        }
    }

    string getHappyString(int n, int k) {
        string s = "abc";
        string ans = "";
        vector<string> v;
        recr(0,s,v,ans,n);
        return v.size() >= k ? v[k-1] : "";
    }
};