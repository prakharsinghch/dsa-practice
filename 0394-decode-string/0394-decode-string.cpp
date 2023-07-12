class Solution {
public:
    string decodeString(string s) {
      int n = s.size(), i=0;
      stack<char> st;
      string ans = "";
      while(i<n){
          if(s[i] == ']'){
              string temp = "";
              while(!st.empty() && (st.top() >= 'a' && st.top() <= 'z') )
              {
                    temp+=st.top();
                    st.pop();
          }
              reverse(temp.begin(),temp.end());
              st.pop();
              
              string temp2 = "";
              while(!st.empty() && (st.top() >= '0' && st.top() <= '9')) {
                  temp2 += st.top();
                  st.pop();
              }
              reverse(temp2.begin(),temp2.end());
              int x = stoi(temp2);
              string s2 = "";
              temp2 = temp;
              for(int i=0;i<x-1;i++){
                  temp+=temp2; 
              }

              for(int k = 0;k<temp.size();k++) st.push(temp[k]);
          }
          else st.push(s[i]);

          i++;
      }
      while(!st.empty()){
          ans+=st.top();
          st.pop();
      }
        reverse(ans.begin() , ans.end());
      return ans;
    }
};