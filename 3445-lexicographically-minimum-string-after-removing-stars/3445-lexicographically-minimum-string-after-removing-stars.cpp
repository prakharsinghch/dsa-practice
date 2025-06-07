class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char,int> , vector<pair<char,int>> , greater<pair<char,int>>> pq;
        unordered_map<int,bool> mp;
        for(int i = 0; i <s.size();i++){
            if(s[i] == '*'){
                mp[i] = true;
                auto x = pq.top();
                mp[abs(x.second)] = true;
                pq.pop();
            }
            else {
                pq.push({s[i] , -i});
            }
        }

        string ans = "" ;
        for(int i= 0;i<s.size();i++){
            if(mp[i] == true ) continue;
            else ans+=s[i];
        }

        return ans;
    }
};