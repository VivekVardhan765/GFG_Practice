//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   

    vector<int> shortestPath(int n, int m, vector<vector<int>>& edge) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            adj[edge[i][0]].push_back({edge[i][1], edge[i][2]});
            adj[edge[i][1]].push_back({edge[i][0], edge[i][2]});
        }
        vector<int> path(n + 1, INT_MAX);
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});  
        path[1] = 0;
        while (!pq.empty()) {
            auto p = pq.top();
            int node = p.second;
            int d = p.first;
            pq.pop();
            for (auto& el : adj[node]) {
                int neighbor = el.first;
                int weight = el.second;
                int dist = d + weight;
                if (dist < path[neighbor]) {
                    path[neighbor] = dist;
                    parent[neighbor] = node;
                    pq.push({dist, neighbor});
                }
            }
        }
        if (path[n] == INT_MAX) return {-1}; 
        vector<int> ans={path[n]};
        stack<int> st;
        int curr = n;
        while (parent[curr] != curr) {
            st.push(curr);
            curr = parent[curr];
        }
        st.push(1);  
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends