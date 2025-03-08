class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX;
        for(int i=0;i<=blocks.size()-k;i++){
            int res = 0;
            for(int j=i;j<i+k;j++){
                if(blocks[j] == 'W') res++;
            }

            ans = min(ans,res);
        }

        return ans;
    }
};