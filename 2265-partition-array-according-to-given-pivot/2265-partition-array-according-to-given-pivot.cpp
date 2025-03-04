class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int> q;
        queue<int> q1;
        int c = 0;
        for(auto x: nums){
            if(pivot < x) q1.push(x);
            else if(pivot > x) q.push(x);
            else c++;
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        while(c--){
            ans.push_back(pivot);
        }
        while(!q1.empty()){
            ans.push_back(q1.front());
            q1.pop(); 
        }

        return ans;
    }
};