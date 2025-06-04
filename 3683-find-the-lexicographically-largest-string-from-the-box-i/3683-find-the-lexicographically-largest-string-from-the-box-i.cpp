class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        int x = word.size()-numFriends +1;
        string ans = "";
        for(int i=0;i<word.size();i++){
            string s = word.substr(i,x);
            ans = max(ans,s);
        }
        return ans;
    }
};