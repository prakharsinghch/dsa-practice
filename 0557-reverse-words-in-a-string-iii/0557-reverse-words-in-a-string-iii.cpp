class Solution {
public:
    string reverseWords(string s) {
        string ans ="";
        string s1 = "";
        for(auto x: s){
            if(x == ' '){
                reverse(s1.begin(),s1.end());
                ans+=s1;
                ans += " ";
                s1 = "";
            } 
            else s1+=x;
        }
        
        reverse(s1.begin(),s1.end());
        ans+=s1;

        return ans;
    }
};