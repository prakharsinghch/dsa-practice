class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        priority_queue<long long,vector<long long>, greater<long long>> pq;
        for(auto x: nums){
            pq.push(x);
        }
        if(pq.top() >=k ) return 0;
        int i=0;
        while(pq.top() < k && !pq.empty()){
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(x*2 + y);
            i++;
        }

        return i;

    

    }
};