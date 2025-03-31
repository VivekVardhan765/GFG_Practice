//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void f(int node,vector<bool>&vis,vector<vector<int>>&adj,vector<int>& ans){
        ans.push_back(node);
        vis[node]=1;
        for(int el:adj[node]){
            if(!vis[el])f(el,vis,adj,ans);
        }
        return;
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>ans;
        vector<bool>vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i])f(i,vis,adj,ans);
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
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

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
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends