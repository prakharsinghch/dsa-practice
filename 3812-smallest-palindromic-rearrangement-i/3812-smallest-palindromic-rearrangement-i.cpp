class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        int i;
        for(i=0;i<n/2;i++){
            ans+=s[i];
        }
        sort(ans.begin(),ans.end());
        string x = ans;
        if(n%2) ans+=s[i];
        reverse(x.begin(),x.end());
        ans = ans+x;
        return ans;
    }
};