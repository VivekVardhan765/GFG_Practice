//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>v(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!v[i][j] and grid[i][j]=='1'){
                    ans++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    v[i][j]=true;
                    while(!q.empty()){
                        auto curr=q.front();
                        int x=curr.first,y=curr.second;
                        v[curr.first][curr.second]=true;
                        q.pop();
                        for(int i1=-1;i1<=1;i1++){
                            for(int j1=-1;j1<=1;j1++){
                                if((x+i1>=0 and x+i1<n) and (y+j1>=0 and y+j1<m)){
                                    if(!v[x+i1][y+j1] and grid[x+i1][y+j1]=='1'){
                                        q.push({x+i1,y+j1});
                                        v[x+i1][y+j1]=true;
                                    }
                                }
                            }
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
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends