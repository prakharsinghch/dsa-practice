class Solution {
public:
    string ans = "";

    void check(string s, int l, int r){
        while(l>=0 && r<s.size()){
            if(s[l] != s[r]){
               break;
            } 
                l--;
                r++;
        }
        if(ans.size() < r-l ) ans=s.substr(l+1,r-l-1);
    }

    string longestPalindrome(string s) {
        for(int i=0;i<s.size();i++){
            check(s,i,i);
            check(s,i,i+1);
        }

        return ans;
    }
};