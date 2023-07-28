class Solution {
public:
    long long maxRunTime(int n, vector<int>& bat) {
        sort(bat.begin(),bat.end(),greater<int>());
        long long sum = 0;
        for(auto x: bat)  sum+=x;
        
        for(int i=0;i<bat.size();i++,n--){
            if(bat[i] <= sum/n) break;
            sum -= bat[i];
        }

        return sum/n;

    }
};