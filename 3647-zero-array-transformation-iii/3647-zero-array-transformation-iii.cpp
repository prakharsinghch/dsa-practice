class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(),queries.end());
        priority_queue<int> avl;
        priority_queue<int,vector<int>,greater<int>> ass;
        int c = 0;
        for(int t=0,k=0;t<nums.size();t++){
            while(!ass.empty() && ass.top() < t) ass.pop();
            while(k < queries.size() && queries[k][0] <= t) avl.push(queries[k++][1]);
            while(ass.size() < nums[t] && !avl.empty() && avl.top() >= t){
                ass.push(avl.top());
                avl.pop();
                c++;
            }
            if(ass.size() < nums[t]) return -1;
        }

        return queries.size() -c;
    }
};