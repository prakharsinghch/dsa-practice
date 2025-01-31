class Solution {
public:
    int myAtoi(string s) {
        int l = s.size();

        if(l==0) return 0;

        int i=0;
        
        while(i<l && s[i] == ' ') 
        {
          
            i++;
        }

        s=s.substr(i);
        
    
        int si = 1;
        long long ans=0;
        
        if(s[0] == '-') {  si = -1; i=1;}
        else if(s[0] == '+') {  si = 1; i=1;}
        else i=0;
        // cout<<s<<" "<<s.length();
        while(i<s.length()){

            if(s[0] == ' ' || !isdigit(s[i])) break;

            ans = ans*10+s[i] - '0';
            i++;
            if(si == -1 && -1*ans<INT_MIN) return INT_MIN;
            if(si== 1 && ans>INT_MAX) return INT_MAX;

            
        } 

        return si*ans;


 
    }
};