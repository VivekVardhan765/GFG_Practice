class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        vector<pair<int,int>>dir={{0,-1},{-1,0},{1,0},{0,1}};
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=0;
                }
                else grid[i][j]=-1;

            }
        }
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                int curr = q.front().first;
                int d= q.front().second;
                q.pop();
                for(auto it:dir){
                    int i1=curr+it.first;
                    int j1=d+it.second;
                    if((i1<n and i1>-1) and (j1<m and j1>-1)){
                        if(grid[i1][j1]==-1){
                            grid[i1][j1]=grid[curr][d]+1;
                            q.push({i1,j1});
                        }
                    }
                }
            }
        }
        return grid;
    }
};