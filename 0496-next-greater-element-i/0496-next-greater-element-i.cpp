class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++) mp[nums2[i]] = i;

        vector<int> ans;

        for(int i=0;i<nums1.size();i++){
            int x = INT_MIN;
            for(int j = mp[nums1[i]];j<nums2.size();j++){
                if(nums2[j] > nums1[i]){
                    x = nums2[j];
                    break;
                }
            }
            if(x == INT_MIN) x=-1;
            ans.push_back(x);
        }

        return ans;
    }
};