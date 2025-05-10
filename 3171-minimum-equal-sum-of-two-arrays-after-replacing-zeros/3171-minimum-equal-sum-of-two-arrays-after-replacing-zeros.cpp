class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = 0, s2=0;
        long long c1= 0 , c2 = 0;
        for(auto x: nums1) {
            s1+=x;
            if(x==0) c1++;
        }
        for(auto x:nums2){
            s2+=x;
            if(x == 0) c2++;
        }
        long long min1 = s1+c1;
        long long min2 = s2+c2;

        if(c1 == 0 && c2 ==0){
            return min1 == min2 ? min1 : -1;
        }else if(c1 == 0){
            return min2 <= s1 ? s1 : -1;
        }else if(c2 == 0){
            return min1 <= s2 ? s2 : -1;
        }

        return max(min1,min2);

    }
};