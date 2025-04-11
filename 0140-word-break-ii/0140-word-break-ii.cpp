class Solution {
public:
    void recr(string& s,vector<string>& res,set<string>& st,int i,string s1){
        if(i==s.size()){
            s1.pop_back();
            res.push_back(s1);
        }
        string str = "";
        for(int j  = i;j<s.size();j++){
            str.push_back(s[j]);
            if(st.count(str)){
                recr(s,res,st,j+1,s1+str+" ");
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto x: wordDict) st.insert(x);
        vector<string> res;
        recr(s,res,st,0,"");
        return res;
    }
};