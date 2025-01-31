class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int lena=a.length(), lenb=b.length();
        int res=0, lendiv=(lenb/lena+2);
        string tstr;
        while(lendiv--){
            tstr+=a;
            res++;
            if(tstr.find(b)!=string::npos)  return res;
        }
        return -1;
    }
};