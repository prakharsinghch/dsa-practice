class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long o=0,pre = 0;
        for(int a : arr){
            pre+=a;
            if(pre%2) o++;
        }
        o+=(arr.size()-o)*o;
        return o % 1'000'000'007;
    }
};