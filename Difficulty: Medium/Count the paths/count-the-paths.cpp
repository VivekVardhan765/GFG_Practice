class Solution {
  public:
    int dfs(int node,vector<vector<int>>& adj,vector<int>& dp){
        if(dp[node]==-1){
            int ans=0;
            for(auto el:adj[node]){
                ans+=dfs(el,adj,dp);
            }
            return dp[node]=ans;
        }else{
            return dp[node];
        }
        
    }
    int countPaths(vector<vector<int>>& edges, int n, int src, int dest) {
        vector<vector<int>>adj(n);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int>dp(n,-1);
        dp[dest]=1;
        return dfs(src,adj,dp);
    }
};