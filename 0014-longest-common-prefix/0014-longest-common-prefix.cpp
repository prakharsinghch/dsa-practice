class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string s = "";
        for(int i=0;i<strs[0].size();i++){
            if(strs[0][i] == strs[strs.size()-1][i]) s+=strs[0][i];
            else break;
        }

        return s;
    }
};