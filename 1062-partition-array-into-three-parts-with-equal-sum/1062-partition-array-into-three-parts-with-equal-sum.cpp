class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for(auto x: arr) sum+=x;

        if(sum%3 == 0) {
            int x = sum/3;
            int c = 0,j=0;
            int s1=0;
            for(int i=0;i<arr.size();i++){
                
                    s1+=arr[i];
                    j++;
                
                if(s1 == x){
                    s1=0;
                    c++;
                    j=0;
                }
            }
            if(s1 == x && j) c++;
            return c>=3;
        }
        return false;
    }
};