class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        int x = word.size()-numFriends +1;
        vector<string> ans;
        for(int i=0;i<word.size();i++){
            string s = word.substr(i,x);
            ans.push_back(s);
        }
        sort(ans.begin(),ans.end());
        return ans.back();
    }
};