class Solution {
public:
    int minMaxDifference(int num) {
        vector<string> res;
        string x = to_string(num);
        for(int i=0;i<x.size();i++){
            auto z = x[i];
            string y = x;
            string y1 = x;
            for(int j = 0;j<x.size();j++ ){
                if(x[j] == z){
                    y[j] = '9';
                    y1[j] = '0'; 
                }
            }

            res.push_back(y);
            res.push_back(y1);
        }

        sort(res.begin(),res.end());

       
        return stoi(res[res.size()-1]) - stoi(res[0]);
    }
};