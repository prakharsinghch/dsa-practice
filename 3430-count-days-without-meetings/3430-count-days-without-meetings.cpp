class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>> ans;
        ans.push_back(meetings[0]);
        for(int i=1;i<meetings.size();i++){
            if(ans.back()[1] >= meetings[i][0] ) ans.back()[1] = max(ans.back()[1],meetings[i][1]);
            else ans.push_back(meetings[i]);
        }
        int c =0;

        for(auto x: ans){
            cout<<x[0]<<" "<<x[1]<<endl;
            c+=x[1]-x[0]+1;
        }
        cout<<c;
        return days-c;
    }
};