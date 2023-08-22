class Solution {
public:
    string convertToTitle(int c) {
        string ans = "";
        int n = c;
        while(n>0){
            n--;
            int q = n/26;
            int r = n%26;
            ans.push_back('A' + r);
            n =q;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};