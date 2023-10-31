class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int x = pref[0];
        vector<int> ans;
        ans.push_back(x);
        for(int i= 1;i<pref.size();i++){
            x = x^pref[i];
            ans.push_back(x);
            x = pref[i];
        }

        return ans;
    }
};