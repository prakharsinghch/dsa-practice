class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> p;
        for(auto x: nums){
            p.push(x);
        }
        k--;
        while(k--){
            p.pop();
        }
        return p.top();
    }

};