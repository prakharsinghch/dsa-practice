class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s;
        for(auto x: wordList) s.insert(x);

        queue<pair<string, int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            string w = q.front().first;
            int t = q.front().second;
            q.pop();

            if(w == endWord) return t;

            for(int i=0;i<w.size();i++){
                char o = w[i];
                for(char c = 'a' ; c<= 'z'; c++){
                    w[i] = c;
                    if(s.find(w) != s.end()){
                        s.erase(w);
                        q.push({w,t+1});
                    }
                }
                w[i] = o;
            }
        }

        return 0;
    }
};