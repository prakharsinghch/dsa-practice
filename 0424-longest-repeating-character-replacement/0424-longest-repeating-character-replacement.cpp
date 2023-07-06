class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int count = 0;
        int ans = INT_MIN;
        map<char,int> v;
        for(int i = 0 ;i<s.size();i++ ){
            v[s[i]]++;
            count = max(count, v[s[i]]);
            if( (i-l+1) - count > k){
                v[s[l]]--;
                l++;
            }

            ans = max(ans, (i-l+1));
         
        }

        // ans = max(ans, i-l+1);

        return ans;
    }
};