class Solution {
public:
    
    
    int minExtraChar(string s, vector<string>& dictionary) {

    //   unordered_set<string> s2;
    //     for(auto x: dictionary){
    //         s2.insert(x);
    //     }
    //     int n=s.size();
    //     int k=0;

    //     for(int i=1;i<=n;i++)
    //     {
    //         for(int j=i-1;j>=0;j--){
    //             string s1=s.substr(j,i-j);
    //             if(s2.count(s1)){
    //                 k+=s1.size();
    //             }
    //         }
    //     }

    //     return n-k;

        unordered_set<string> d;
        for(auto x: dictionary){
            d.insert(x);
        }
        int n=s.size();
        vector<int> x(n+1);
 

        for(int i=1;i<=n;i++){
            x[i] = x[i-1]+1;

            for(int j = i-1;j>=0;j--){
                string s1 = s.substr(j,i-j);
                if(d.count(s1)){
                    x[i] = min(x[i],x[j]);
                }
            }
        }

        return x[n];

    }
};