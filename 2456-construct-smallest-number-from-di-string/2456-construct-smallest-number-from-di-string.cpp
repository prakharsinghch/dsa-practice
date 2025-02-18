class Solution {
public:
    string smallestNumber(string pattern) {
        stack<char> st;
        char a = '1';
        string ans = "";
        for(auto x: pattern){
            if(x == 'I'){
                ans+=a;
                while(!st.empty()) {
                    ans+=st.top();
                    st.pop();
                }
            }
            else st.push(a);
            a++;
        }
        ans+=a;
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }

        return ans;
    }
};