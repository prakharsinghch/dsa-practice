class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> ans;
        stack<int> st;
        for(int i = 0;i<a.size();i++){
            if(a[i] < 0 && st.empty()) 
            {
                ans.push_back(a[i]);
                continue;
            }
            else if(a[i] > 0) st.push(a[i]);
            else {
                
                while(!st.empty()){
                    int x = st.top();
                    if(x > abs(a[i])){
                        break;
                    }
                    else if( x == abs(a[i])){
                        st.pop();
                        break;
                    }
                    else{
                        st.pop();
                        if(st.size() == 0) ans.push_back(a[i]);
                    }
                }
            }
        }

        vector<int> out;
        while(!st.empty()){
            out.push_back(st.top());
            st.pop();
        }
        reverse(out.begin(), out.end());
        for(int i = 0; i < out.size(); i++){
            ans.push_back(out[i]);
        }

        return ans;

    }
};