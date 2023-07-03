class Solution {
public:
    bool buddyStrings(string s, string goal) {
        set<char> st;
        if(s == goal){
            for(int i=0;i<s.size();i++) st.insert(s[i]);
            return st.size() < goal.size();
        }

        int i = 0;
        int j = s.size()-1;

        while(i < j && s[i] == goal[i]){
            i++;
        }

        while( j >= 0 && s[j] == goal[j]) j--;

        if(i<j) swap(s[i],s[j]);

        return s==goal;
    }
};