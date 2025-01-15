//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool dfs(int parent,int node,vector<vector<int>>& adj,vector<bool>& v){
        v[node]=true;
        for(int el:adj[node]){
            if(el!=parent){
                if(v[el])return true;
                if(dfs(node,el,adj,v))return true;
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<bool>v(n,false);
        for(int i=0;i<n;i++){
            if(!v[i]){
                if(dfs(-1,i,adj,v))return true;
            }
        }
        return false;
        
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
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends