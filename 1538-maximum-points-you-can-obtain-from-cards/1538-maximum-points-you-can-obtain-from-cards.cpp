class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans =0;
        for(int i=0;i<k;i++) ans+=cardPoints[i];
        int n=cardPoints.size()-1;
        int curr =  ans;
        for(int i=k-1;i>=0;i--){
            curr -=cardPoints[i];
            curr+= cardPoints[n];
            
            ans =  max(ans,curr);
            n--;
        }

        return ans;
    }
};