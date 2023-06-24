class Solution {
public:

    bool palindrome(string s, int i, int ind){
        while(ind<i){
            if(s[i]!=s[ind]) return false;
            i--;
            ind++;
        }
        return true;
    }

    void recr(string s,vector<vector<string>>& ans, vector<string> v , int ind){
        if(ind ==  s.size()){
            ans.push_back(v);
            return ;
        }

        for(int i= ind;i<s.size();i++){
            if(palindrome(s,i,ind)){
                string s1 = s.substr(ind,i-ind+1);
                v.push_back(s1);
                recr(s,ans,v,i+1);
                v.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        recr(s,ans,v,0);
        return ans;
    }
};