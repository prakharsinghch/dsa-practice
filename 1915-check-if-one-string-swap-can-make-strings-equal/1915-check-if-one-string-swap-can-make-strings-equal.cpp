class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i =0,c=0;
        for(auto x:s1){
            if(x!=s2[i]) c++;
            i++;
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1 != s2 ) return false;
        if(c==2 || c==0) return true;
        return false;

        // return s1 == s2;
    }
};