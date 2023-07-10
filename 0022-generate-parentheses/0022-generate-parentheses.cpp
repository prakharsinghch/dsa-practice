class Solution {
public:

    void solve(int c1, int c2, string s, vector<string>& ans){
        if(c1 == 0 && c2 == 0 ){
            ans.push_back(s);
            return;
        }

        if(c1 == c2){
            string s1 = s;
            s1.push_back('(');
            solve(c1-1,c2,s1,ans);
        }

        else if(c1 == 0){
            string s1 = s;
            s1.push_back(')');
            solve(c1,c2-1,s1,ans);
        }

        else {
            string s1 = s,s2 = s;
            s1.push_back('(');
            s2.push_back(')');
            solve(c1-1,c2,s1,ans);
            solve(c1,c2-1,s2,ans);
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string  s ="";
        solve(n,n,s,ans);
        return ans;
    }
};