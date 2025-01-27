class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;
        unordered_map<int, unordered_set<int>> mp;
        for(auto x: prerequisites){
            mp[x[1]].insert(x[0]);
        }
        for(int i = 0;i<numCourses;i++){
            for(int j = 0;j<numCourses;j++){
                if(mp[j].count(i)){
                    for(auto x: mp[i]) mp[j].insert(x);
                }
            }
        }

        for(auto x: queries){
            if(mp[x[1]].count(x[0])) ans.push_back(1);
            else ans.push_back(0);
        }

        return ans;
    }
};