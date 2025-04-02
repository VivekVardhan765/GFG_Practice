//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n=adj.size();
        vector<int>vis(n);
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                q.push(i);
                vis[i]=true;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    ans.push_back(node);
                    for(int el:adj[node]){
                        if(!vis[el]){
                            q.push(el);
                            vis[el]=true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        // Use vector of vectors instead of array of vectors.
        vector<vector<int>> adj(V);

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.bfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends