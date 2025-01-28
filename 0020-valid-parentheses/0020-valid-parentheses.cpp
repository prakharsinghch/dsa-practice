class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(auto x:s){
          if(x == '(' || x == '{' || x=='[' ) t.push(x);
           else{
               if(t.empty() || (x == ')' && t.top() != '(') || 
                    (x == '}' && t.top() != '{') ||
                    (x == ']' && t.top() != '[')) {
                        return false;
                    } 
                t.pop();
           }
        }

        return t.empty();
    }
};