class Solution {
  public:
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        vector<pair<int,int>>dir={{0,-1},{1,0},{0,1},{-1,0}};
        int n=grid.size();
        int m=grid[0].size();
        stack<pair<int,int>>st;
        vector<vector<bool>>vis(n,vector<bool>(m));
        int count=0;
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                st.push({i,0});
                vis[i][0]=1;
                count++;
            }
            if(!vis[i][m-1] and grid[i][m-1]==1){
                st.push({i,m-1});
                count++;
                vis[i][m-1]=1;
            }
        }
        for(int j=1;j<m-1;j++){
            if(!vis[0][j] and grid[0][j]==1){
                st.push({0,j});
                vis[0][j]=1;
                count++;
            }
            if(!vis[n-1][j] and grid[n-1][j]==1){
                st.push({n-1,j});
                vis[n-1][j]=1;
                count++;
            }
            
            
        }
        while(!st.empty()){
            auto [i,j]=st.top();
            st.pop();
            for(auto [i1,j1]: dir){
                if( i+i1< n and j+j1 < m and i+i1>-1 and j+j1>-1 and !vis[i+i1][j+j1]){
                    if( grid[i+i1][j+j1]==1){
                        st.push({i+i1,j+j1});
                        vis[i+i1][j+j1]=1;
                        count++;
                    }
                }
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count-=grid[i][j];
            }
        }
        return abs(count);
    }
};