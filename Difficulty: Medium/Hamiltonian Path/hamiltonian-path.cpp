class Solution {
  public:
    bool dfs(int curr, int count, vector<bool>& vis, vector<vector<int>>& adj, int n) {
        vis[curr] = true;
    
        if (count == n) {
            return true;
        }
    
        for (int neighbor : adj[curr]) {
            if (!vis[neighbor]) {
                if (dfs(neighbor, count + 1, vis, adj, n)) {
                    return true;
                }
            }
        }
    
        vis[curr] = false; 
        return false;
    }
    
    bool check(int n, int m, vector<vector<int>> edges) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for (int start = 1; start <= n; ++start) {
            vector<bool> vis(n + 1, false);
            if (dfs(start, 1, vis, adj, n)) {
                return true;
            }
        }
    
        return false;
    }
};
