class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, h = n-1;
        int t1=0,t2=0,ans = 0;
        while(l<h){
            t1 = min(height[l], height[h])*(h-l);
            ans = max(t1,ans);
            if(height[l] < height[h]) l++;
            else h--;
        }
        return ans;
    }
};