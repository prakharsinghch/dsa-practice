class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int x = low;x<=high;x++){
            string i = to_string(x);
            if(i.size()%2 == 0){
                int a = 0, b = 0;
                for(int j = 0;j<i.size()/2;j++) a+= i[j] -'0' ;
                for(int j = i.size()/2;j<=i.size()-1;j++) b+= i[j] -'0' ;
                
                if(a == b) ans++;
            }
        }

        return ans;
    }
};