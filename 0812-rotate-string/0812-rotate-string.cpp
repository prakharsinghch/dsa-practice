class Solution {
public:
    bool rotateString(string s, string goal) {
        string s1 = goal+goal;
        for(int i=0;i<s1.size()-s.size();i++){
            if(s1.substr(i,s.size()) == s) return true;
        }

        return false;
    }
};