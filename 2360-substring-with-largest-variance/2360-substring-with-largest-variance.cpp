class Solution {
public:
    int largestVariance(string s) {
        vector<int> arr(26);
        for(auto x: s){
            arr[x-'a']++;
        }
        int ans=0;
        for(char i = 'a'; i<='z' ; i++){
            for(char j = 'a'; j<='z';j++){
                if(j == i || arr[i-'a'] == 0 || arr[j-'a'] == 0) continue;
                for(int k =1; k<=2; k++){
                    int a1 = 0;
                    int a2 = 0;
                    for(auto x: s){
                        if(x == i) a1++;
                        if(x == j) a2++;
                        if(a2>a1) {
                            a1 = 0;
                            a2 = 0;
                        }
                        if(a1>0 && a2>0) ans = max(ans, a1-a2);
                    }
                    reverse(s.begin(),s.end());
                }
            }
        }

        return ans;
    }
};