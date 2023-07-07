class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int j=0;
        int i = 0;
        int ans = INT_MIN;
        int count = 0;
        int t=0,f=0;
        while(i<s.size()){
            t += (s[i] == 'T');
            f += (s[i] == 'F');
            while(t > k && f > k){
                if(s[j] == 'T') t--;
                else f--;
                j++;
            }
            ans = max(ans, i-j+1);
            i++;

        }
        return ans;
    }
};