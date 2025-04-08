//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int find(int node,vector<int>& parent){
        if(parent[node]==node)return node;
        return parent[node]=find(parent[node],parent);
    }
    void u(int a,int b,vector<int>& parent, vector<int>& rank){
        int pa=find(a,parent);
        int pb=find(b,parent);
        if(rank[pa]<rank[pb]){
            parent[pa]=parent[pb];
        }
        else if(rank[pa]==rank[pb]){
            parent[pa]=parent[pb];
            rank[pb]++;
        }
        else{
            parent[pb]=pa;
        }
    }
    bool isBridge(int n, vector<vector<int>> &edges, int c, int d) {
        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (auto edge : edges) {
            if (!((edge[0] == c && edge[1] == d) || (edge[0] == d && edge[1] == c))) {
                u(edge[0], edge[1], parent, rank);
            }
        }
    
        return find(c, parent) != find(d, parent);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends