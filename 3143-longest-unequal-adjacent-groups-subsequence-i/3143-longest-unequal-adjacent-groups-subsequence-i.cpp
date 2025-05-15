class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int x = 0;
        ans.push_back(words[x]);
        for(int i=1;i<words.size();i++){
            if(groups[x] != groups[i]){
                ans.push_back(words[i]);
                x = i;
            }
        }

        return ans;
    }
};