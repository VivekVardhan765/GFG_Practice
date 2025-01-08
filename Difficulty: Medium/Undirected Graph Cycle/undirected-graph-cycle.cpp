//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<bool>v(n,false);
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(!v[i]){
                q.push({i,-1});
                v[i]=true;
                while(!q.empty()){
                    int curr=q.front().first;
                    int parent=q.front().second;
                    q.pop();
                    for(int el:adj[curr]){
                        if (!v[el]) {  
                            q.push({el, curr});
                            v[el] = true;
                        } else if (el != parent) {
                            return true;
                        }
                    }
                }
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