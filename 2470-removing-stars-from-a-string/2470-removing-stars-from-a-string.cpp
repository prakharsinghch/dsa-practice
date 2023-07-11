class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int c = 0;
        for(auto x:s){
            if(x == '*') 
            {
                st.pop();
            }
            else st.push(x);
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        

        return ans;
    }
};