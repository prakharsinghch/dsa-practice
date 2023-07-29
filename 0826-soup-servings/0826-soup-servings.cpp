class Solution {
public:

    double recr(int a, int b, map<pair<double,double>,double>& mp){
        if(a<= 0 && b<= 0) return 0.5;
        if(a <= 0 && b>0) return 1;
        if(a > 0 && b <= 0) return 0;
        if(mp.find({a,b}) != mp.end()) return mp[{a,b}];
        double o1 = recr(a-100,b,mp);
        double o2 = recr(a-75,b-25,mp);
        double o3 = recr(a-50,b-50,mp);
        double o4 = recr(a-25,b-75,mp);

        return mp[{a,b}] = 0.25*(o1+o2+o3+o4);
    }

    double soupServings(int n) {
        if (n >= 4800) return 1;
        map<pair<double,double>,double> mp;
        return recr(n,n,mp);
    }
};