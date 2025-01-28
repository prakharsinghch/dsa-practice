class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        int n =heights.size();

        for(int i=0;i<=n;i++){
            int curr = (i==n)  ? 0 : heights[i];
            while(!st.empty() && heights[st.top()] > curr){
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top()-1;
                ans = max(ans,h * w);
            }
            st.push(i);    

        }
        return ans;
    }
};