//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bfs(int sr, int sc, vector<vector<int>>& image, vector<vector<bool>>& visited, int newColor) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;
    
        int originalColor = image[sr][sc];
        image[sr][sc] = newColor;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int ci = curr.first;
            int cj = curr.second;
            for (auto dir : directions) {
                int ni = ci + dir.first;
                int nj = cj + dir.second;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                    !visited[ni][nj] && image[ni][nj] == originalColor) {
                    visited[ni][nj] = true;
                    image[ni][nj] = newColor;
                    q.push({ni, nj});
                }
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        if (image[sr][sc] != newColor) {
            bfs(sr, sc, image, visited, newColor);
        }
    
        return image;
    }

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends