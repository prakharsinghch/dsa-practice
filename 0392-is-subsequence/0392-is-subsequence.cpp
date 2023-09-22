class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for(int k =0;k<t.size();k++){
            if(s[i] == t[k]) i++;
        }

        if(i == s.size()) return true;
        return false;
    }
};