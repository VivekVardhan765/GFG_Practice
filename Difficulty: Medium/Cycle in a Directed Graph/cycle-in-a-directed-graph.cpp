//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    bool isCyclic(int n, vector<vector<int>> adj) {
       vector<int>ind(n,0);
        for(int i=0;i<n;i++){
            for(int el:adj[i]){
                ind[el]++;
            }
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(int el:adj[curr]){
                ind[el]--;
                if(ind[el]==0)q.push(el);
            }
        }
        if(ans.size()!=n)return true;
        return 0;
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