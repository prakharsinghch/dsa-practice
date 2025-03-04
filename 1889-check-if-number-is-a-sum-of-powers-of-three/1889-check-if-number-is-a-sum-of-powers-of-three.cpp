class Solution {
public:

    bool recr(vector<int>&p,int n, int s, int i){
        if(s > n) return false;
        else if(s == n) return true;

        if(i >= p.size()) return false;

        return recr(p,n,s+p[i],i+1) || recr(p,n,s,i+1);


    }

    bool checkPowersOfThree(int n) {
        vector<int> p;
        int mx = 1e7;
        p.push_back(1);
        while(p.back() <= mx){
            p.push_back(p.back()*3);
        }

        return recr(p,n,0,0);
    }
};