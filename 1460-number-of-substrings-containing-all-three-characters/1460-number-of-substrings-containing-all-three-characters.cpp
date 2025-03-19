class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp = {{'a',0},{'b',0},{'c',0}};
        int ans = 0, l=0;
        for(int i=0 ;i<s.size();i++){
            mp[s[i]]++;
            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
                ans+= s.size()-i;
                mp[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};