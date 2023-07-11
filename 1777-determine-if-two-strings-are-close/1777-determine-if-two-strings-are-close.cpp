class Solution {
public:
    bool closeStrings(string w1, string w2) {
        map<char, int> m1,m2;
        set<char> s;
        for(int i=0; i<w1.size();i++){
            m1[w1[i]]++;
            s.insert(w1[i]);
        }
        for(int i=0; i<w2.size();i++){
            m2[w2[i]]++;
            s.erase(w2[i]);
        }

        vector<int> v1,v2;

        for(auto x: m1){
            v1.push_back(x.second);
        }
        
        for(auto x: m2){
            v2.push_back(x.second);
        }

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        return (s.empty() &&  v1 == v2 );
    }
};