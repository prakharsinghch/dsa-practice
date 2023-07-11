class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
    

        for(int j = 0;j<t.size();j++){
            if(i == s.size()) return true;
            if(s[i] == t[j]) i++;
            
        }
        //cout<<i<<endl;
        if(i == s.size()) return true;
        return false;
        
    }
};