class Solution {
    vector<int> ans;
    int flag =1;
    void BFS(int src, int des, vector<vector<int>> &graph,vector<int> &visited)  {
        queue<int> q;
        q.push(src);
        
        while(!q.empty())  {
            int top = q.front();
            q.pop();
            if(visited[top])
                return;
            visited[top] = 1;
            
            if(top == des)  {                
                ans = {src, des};
                flag = 0;
                return;
            }
            
            for(auto &i: graph[top])  {
                if(visited[i]==0)  {
                    if(top==src && i==des)
                        continue;
                    else
                        q.push(i);
                }
            }
        }
        return;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n+1);
        
        for(int i=0; i<edges.size(); ++i)  {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        for(int i=n-1; i>=0; --i)  {
            if(flag)  {
                vector<int> visited(n+1,0);
                BFS(edges[i][0],edges[i][1],graph, visited);    
            }            
        }
        
        return ans;
    }
};