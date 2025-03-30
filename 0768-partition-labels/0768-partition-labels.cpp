class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last;
        for(int i=0;i<s.size();i++){
            last[s[i]] = i;
        }
        vector<int> result;
        int st = 0, end =0;
        for(int i=0;i<s.size();i++){
            end = max(end,last[s[i]]);
            if(i == end){
                result.push_back(end-st+1);
                st = i+1;
            }
        }
        return result;
    }
};