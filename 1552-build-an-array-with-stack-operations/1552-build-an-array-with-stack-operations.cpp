class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 1;
        for(auto x: target){
            if(x == i){
                ans.push_back("Push");
                i++;
            }
            else{
                for(int j =i ;j<x;j++){
                    ans.push_back("Push");
                    ans.push_back("Pop");
                }
                i=x;
                i++;
                ans.push_back("Push");
                
            }
        
        }

        return ans;
    }
};