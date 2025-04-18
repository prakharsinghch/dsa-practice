class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        string s = "1";
        while(n-- > 1){
            string s1 = "";
            s1 = ans;
            ans = "";
            int c = 0;
            char x;
            for(int i=0;i<s1.size();i++){
                if(c == 0 || i == 0){
                    c++;
                    x = s1[i];
                }
                else if(s1[i] == x){
                    c++;
                }
                else{
                    ans+=to_string(c);
                    ans+=x;
                    c = 1;
                    x = s1[i];
                }
            }
            ans+=to_string(c);
            ans+=x;
            c = 0;

            cout<<ans<<endl;
        }

        return ans;
    }
};