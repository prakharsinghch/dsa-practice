class Solution {
public:

    bool recr(string s, set<string> t,int start){
        if(start == s.length()) return true;

        for(int i=start;i<s.length();i++){
            string s1 = s.substr(start,i+1-start);
            if(t.count(s1) && recr(s,t,i+1) ) return true;
        }
        
        return false;

    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> t;
        
        for(auto x: wordDict) t.insert(x);

        return recr(s,t,0);
    }

};