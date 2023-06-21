class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,n = nums1.size(),m = nums2.size();
        long long s1 = 0, s2 =0;
        int mo = 1e9+7;
        while(i<n || j<m){
            if(i<n && ( j == m ||nums1[i] < nums2[j]) )
            {
                s1+=nums1[i]%mo;
                i++;
            }
            else if(j<m && ( i==n || nums1[i] > nums2[j])){
                s2+=nums2[j]%mo;
                j++;
            }
            else{
                s1 = (max(s1,s2)+nums1[i])%mo;
                s2=s1;    
                i++;
                j++;
            }
        }
        return max(s1,s2)%mo;
    }
};