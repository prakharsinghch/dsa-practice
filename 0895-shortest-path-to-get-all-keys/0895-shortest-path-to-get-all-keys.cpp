class Solution {
public:
	vector<int> dx{-1,0,1,0};
	vector<int> dy{0,-1,0,1};
	int shortestPathAllKeys(vector<string>& grid) {
		int m=grid.size(),n=grid[0].length();
		int keysCnt=0;
		queue<vector<int>> q;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(grid[i][j]>='a' && grid[i][j]<='z') keysCnt++;
				if(grid[i][j]=='@') q.push({i,j,0});
			}
		}

		int ans=0;
		set<vector<int>> st;
		while(!q.empty()){
			int sz=q.size();
			for(int k=0;k<sz;k++){
				auto p=q.front();
				int x=p[0];
				int y=p[1];
				int mask=p[2];
				q.pop();

				if(__builtin_popcount(mask)==keysCnt) return ans;
				for(int i=0;i<4;i++){
					int ni=x+dx[i];
					int nj=y+dy[i];
					int nMask=mask;

					if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]!='#'){
						if(isupper(grid[ni][nj])){
							if((mask&(1<<(grid[ni][nj]-'A')))==0) continue;
						}
						else if(islower(grid[ni][nj])){
							nMask=mask|(1<<(grid[ni][nj]-'a'));
						}

						if(!st.count({ni,nj,nMask})){
							st.insert({ni,nj,nMask});
							q.push({ni,nj,nMask});
						}
					}
				}
			}
			ans++;
		}
		return -1;
	}
};