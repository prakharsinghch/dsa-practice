class Solution {
public:

    static bool comp(int a, int b){
        string x = to_string(a) + to_string(b);
        string y = to_string(b) + to_string(a);
        return x > y;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        string ans = "";
        for(auto x: nums){
            ans += to_string(x);
        }
        if(ans[0] == '0') return "0";
        return ans;
    }
};