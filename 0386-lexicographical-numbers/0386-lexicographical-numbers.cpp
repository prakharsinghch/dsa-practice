class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<10;i++){
            recr(i,n,ans);
        }

        return ans;
    }

    void recr(int i,int n, vector<int>& ans){
        if(i > n) return;
        ans.push_back(i);
        for(int j=0;j<10;j++){
            int nxt = i*10+j;
            if(nxt > n) return;
            recr(nxt,n,ans);
        }
    }
};