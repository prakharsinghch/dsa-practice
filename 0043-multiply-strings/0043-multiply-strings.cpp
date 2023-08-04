class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        string ans(size(num1)+size(num2), '0');
        for(int i = num1.size()-1; i>=0;i--){
            for(int j = num2.size()-1;j>=0;j--){
                int res = ans[i+j+1] + (num1[i]-'0')*(num2[j] - '0')-'0';
                ans[i+j+1] = res%10 + '0';
                ans[i+j]+= res/10;
            }
        }

        if(ans[0] == '0') return ans.substr(1);
        return ans;
    }
};