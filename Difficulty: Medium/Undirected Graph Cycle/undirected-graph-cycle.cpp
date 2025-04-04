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
    void Union(int i,int j,vector<int>& parent,vector<int>& rank){
        int ip=find(i,parent);
        int jp=find(j,parent);
        if(rank[jp]==rank[ip]){
            parent[jp]=ip;
            rank[ip]++;
        }
        else if(rank[jp]<rank[ip])parent[jp]=ip;
        else parent[ip]=jp;
    }
    bool isCycle(int n, vector<vector<int>>& edges) {
        vector<int>parent(n),rank(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto it:edges){
            int i=it[0],j=it[1];
            if(find(i,parent)==find(j,parent))return true;
            else Union(i,j,parent,rank);
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
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