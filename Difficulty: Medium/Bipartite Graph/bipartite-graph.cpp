//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& curr,int colour){
        curr[node]=colour;
        for(int el:adj[node]){
            if(curr[el]==-1){
                if(dfs(el,adj,curr,(colour+1)%2))return true;
            }
            else{
                if(curr[el]==colour)return true;
            }
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>curr(n,-1);
        for(int i=0;i<n;i++){
            if(curr[i]==-1){
                if(dfs(i,adj,curr,0)==true)return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends