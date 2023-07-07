class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {



    //   vector<int> ans;
    //     int mx, i,j ;
    //   for(i=0;i<nums.size()-k+1;i++){
    //        mx = INT_MIN;
    //       for(j=i;j<i+k;j++){
    //           mx = max(mx,nums[j]);
    //       }
    //       ans.push_back(mx);
    //   }
 
    //   return ans;


    vector<int> ans;
    priority_queue<pair<int,int>, vector<pair<int,int>> > pq;
    int ind=0;
    for(int i = 0;i<k;i++){
        pq.push( {nums[i] , i});
    }
    ans.push_back(pq.top().first);
    for(int i=k;i<nums.size();i++){
        pq.push({ nums[i], i});
        while(pq.top().second <= i - k){
            pq.pop();
        }
        ans.push_back(pq.top().first);
        ind++;
    }

    return ans;

    }
};