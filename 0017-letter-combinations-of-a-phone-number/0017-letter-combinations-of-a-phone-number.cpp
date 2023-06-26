class Solution {
public:

    void recr(string digits, unordered_map<int,string>& m, vector<string>& ans, string s, int i){
        if(s.length() == digits.size()){
            ans.push_back(s);
            return;
        }

        int ind = digits[i]-'0';
        string temp = m[ind];
        for(int j=0;j<temp.size();j++){
            s.push_back(temp[j]);
            recr(digits,m,ans,s,i+1);
            s.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {

        

        unordered_map<int,string> m;
        m[1] = ""; m[2] = "abc"; m[3] = "def"; m[4] = "ghi" ; m[5] = "jkl"; m[6] = "mno"; m[7] = "pqrs" ; m[8] = "tuv" ; m[9] = "wxyz";

        vector<string> ans;
        string s = "";
        if(digits == "") return ans;
        recr(digits,m,ans,s,0);


        return ans;
    }
};