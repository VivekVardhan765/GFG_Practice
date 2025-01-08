//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        int count=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    q.push({i,j});
                }
                if(mat[i][j]==1)count++;
            }
        }
        if(count==0)return 0;
        vector<pair<int,int>>del={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto curr=q.front();
                q.pop();
                int x=curr.first;
                int y=curr.second;
                for(int i=0;i<4;i++){
                    int x1=x+del[i].first;
                    int y1=y+del[i].second;
                    if(x1>=0 and y1>=0 and x1<n and y1<m){
                        if(mat[x1][y1]==1){
                            count--;
                            mat[x1][y1]=2;
                            q.push({x1,y1});
                        }
                    }
                }
            }
            ans++;
        }
        if(count==0)return ans-1;
        else return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends