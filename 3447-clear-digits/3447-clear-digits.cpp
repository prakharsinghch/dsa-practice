class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(auto x: s){
            if(x - '0' >= 0 && x-'0'<=9) st.pop();
            else st.push(x);
        }
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};