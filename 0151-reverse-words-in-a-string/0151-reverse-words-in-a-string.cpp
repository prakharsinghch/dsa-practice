class Solution {
public:
    string reverseWords(string s) {
        string s2 ="";
        int i=0,end=s.size()-1;
        stack<string> s1;
        
        for(int i = s.size()-1;i>=0;i--){
            if(s[i] == ' '){
                if(end != i) s2.append(s.substr(i+1,end-(i+1)+1)+' ');

                end = i-1;
            }
        }

        if(s[0] != ' ') s2.append(s.substr(0,end+1) + ' ');

        s2.pop_back();
        return s2;

    }
};