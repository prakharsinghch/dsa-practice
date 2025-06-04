class Solution {
public:

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        __int128 c = 1;
        for(auto x: nums) {
            if(target%x != 0 ) return false;
            c*=x;
        }

        return c/target == target;
    }
};