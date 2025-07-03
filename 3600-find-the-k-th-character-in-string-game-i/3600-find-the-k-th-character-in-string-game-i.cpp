class Solution {
public:
    char kthCharacter(int k) {
        string ans = "a";
        while(ans.size() <= k){
            string nxt = ans;
            for(int i= 0 ; i <nxt.size();i++){
                if(nxt[i] == 'z') nxt[i] = 'a';
                else nxt[i]++;
            }
            ans += nxt;
        }
        cout<<ans<<endl;
        return ans[k-1];
    }
};