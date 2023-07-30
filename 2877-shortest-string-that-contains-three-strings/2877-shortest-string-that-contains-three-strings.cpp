class Solution {
public:

    string check(string a, string b){
        if(a.find(b) != string::npos) return a;

        for(int i=min(a.size(), b.size()); i>=0;i--){
            if(a.substr(a.size()-i) == b.substr(0,i) ){
                return a+b.substr(i);
            }
        }

        return a + b;
    }


    void isValid(string merge, string& ans){
        if(ans.empty() || merge.length() < ans.length() || (merge.length() == ans.length() && merge< ans)){
            ans = merge;
        }
    }

    string minimumString(string a, string b, string c) {
        vector<string> v = {a,b,c};

        int n = v.size();
        string ans = "";

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k = 0;k<n;k++){
                    if(i != j && j !=k && i != k){
                        string merge = check(v[i],v[j]);
                        merge = check(merge, v[k]);
                        isValid(merge,ans);
                    }
                }
            }
        }

        return ans;
    }
};