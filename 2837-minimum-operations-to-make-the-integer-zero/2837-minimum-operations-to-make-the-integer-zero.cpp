class Solution {
public:
    int makeTheIntegerZero(int nums1, int nums2) {
        for(int i=0;i<100;i++){
            long t = (long)nums1 - (long)i*nums2;
            if(t<0) continue;
            vector<long> v;
            for(int k=0;k<61;k++){
                if( ( (1l<<k) & t ) != 0) v.push_back(1l<<k);
            }
            long sum = 0;
            for(auto x: v) sum+=x;
            if(v.size()<= i && sum>=i ) return i;
        }
        return -1;
    }
};