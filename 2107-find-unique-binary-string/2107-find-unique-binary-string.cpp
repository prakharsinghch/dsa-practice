class Solution {
public:
    string ans = "";
    void recr(int len, string x, int& n, set<string>& s){
        if(ans == ""){
            if(len == n){
                if(s.find(x) == s.end()) ans = x;
                return;
            }
            for(char i='0';i<='1';i++){
                x+=i;
                recr(len+1,x,n,s);
                x = x.substr(0,x.size()-1);
            }
    
        }
    }

    string findDifferentBinaryString(vector<string>& nums) {
        set<string> s;
        for(auto x: nums) s.insert(x);
        int n=nums[0].size();
        recr(0,"",n,s);
        return ans;
    }
};