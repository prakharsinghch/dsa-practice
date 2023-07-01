class Solution {
public:

    bool check(vector<int>x, vector<int> v){
        for(int i=0;i<26;i++){
            if(x[i] != v[i]) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string m) {
    
        vector<int> ans;
        int n = s.size(), p = m.size();
        vector<int> v(26,0);
        vector<int> x(26,0);

        for(auto f: m){
            x[f-'a']++;
        }

        for(int i=0;i<s.size();i++){
            if(i<p-1) v[s[i]-'a']++;
            else if( i == p-1){
                v[s[i] - 'a']++;
                if(check(x,v)) ans.push_back(i-p+1);
            }
            else{
                v[s[i-p]-'a']--;
                v[s[i]-'a']++;
                if(check(x,v)) ans.push_back(i-p+1);
            }
        }

        return ans;
    }
};