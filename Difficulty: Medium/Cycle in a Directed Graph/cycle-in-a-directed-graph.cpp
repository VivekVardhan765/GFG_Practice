//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<vector<int>>& adj,vector<bool>& vis,vector<bool>& inrec){
        vis[node]=true;
        inrec[node]=true;
        for(int el:adj[node]){
            if(!vis[el]){
                if(dfs(el,adj,vis,inrec))return true;
            }
            else{
                if(inrec[el])return true;
            }
        }
        inrec[node]=false;
        return false;
    }
    bool isCyclic(int n, vector<vector<int>> adj) {
        // code here
        vector<bool>vis(n,false),inrec(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,inrec))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends