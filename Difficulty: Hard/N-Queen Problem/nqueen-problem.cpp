//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool safe(int row,int col,vector<vector<int>>& board){
        int n=board.size();
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 1) return false;
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) return false;
        }
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 1) return false;
        }
        return true;
    }
    void f(int ind,int n,vector<vector<int>>& ans,vector<vector<int>>& board,vector<int>& cont){
        if(ind==n){
            ans.push_back(cont);
            return;
        }
        for(int i=0;i<n;i++){
            if(safe(ind,i,board)){
                board[ind][i]=1;
                cont.push_back(i+1);
                f(ind+1,n,ans,board,cont);
                board[ind][i]=0;
                cont.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>ans;
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<int>cont;
        f(0,n,ans,board,cont);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends