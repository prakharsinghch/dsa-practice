class Solution {
public:

    bool check(string s){
        int n = s.length();
        int i = 0, j = n-1;
        while(i < j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    

    int longestPalindrome(string s, string t) {
        int n=s.size(), m =t.size();
        int res = 1;
        for(int i=0;i<n;i++){
            string s1 = "";
            for(int j=i;j<n;j++){
                s1+=s[j];
                if(check(s1)) res = max(res,j-i+1);
                for(int k=0;k<m;k++){
                    string t1="";
                    for(int l=k;l<m;l++){
                        t1+=t[l];
                        if(check(t1)) res = max(res,l-k+1);
                        if(check(s1+t1)){
                            int len = s1.size()+t1.size();
                            res = max(res,len);
                        }
                    }
                }
            }
        }
        return res;
    }
};