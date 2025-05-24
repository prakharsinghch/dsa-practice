class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i=0;i<words.size();i++){
            string z = words[i];
            for(auto j: z){
                if(j == x){
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};