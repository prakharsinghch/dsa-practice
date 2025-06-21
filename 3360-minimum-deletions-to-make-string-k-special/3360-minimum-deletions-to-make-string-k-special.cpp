class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);
        for(auto x: word){
            freq[x-'a']++;
        }
        int ans = INT_MAX;
        for(int i= 0 ; i <26;i++){
            int c = freq[i];
            int res = 0 ;
            for(int j=0;j<freq.size();j++){
                if(j == i ) continue;
                if(freq[j]  < c) res+=freq[j];
                else if( freq[j] > c+ k) res+=freq[j]-c-k;
            }

            ans = min(ans,res);
        }

        return ans;
    }
};