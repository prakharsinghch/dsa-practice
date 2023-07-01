class Solution {
    bool helper(string &s, string &p, int i, int j){
        if(i<0)return j<0;
        if(j>=0 && (s[i]==p[j] || s[i]=='.')){return helper(s,p,i-1,j-1);}
        else if(s[i]=='*')
        {
            if(helper(s,p,i-2,j))return true;
            char m = s[i-1];
            while(j>=0 && (p[j]==m || m == '.')){
                j--;
                if(helper(s,p,i-2,j))return true;
            }  
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        return helper(p,s,p.size()-1, s.size()-1);
    }
};