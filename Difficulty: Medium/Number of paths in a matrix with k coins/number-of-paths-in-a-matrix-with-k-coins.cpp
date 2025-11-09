class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& mat, int rem, vector<vector<vector<int>>>& dp) {
        if (rem < 0) return 0; // safety
        int n = mat.size(), m = mat[0].size();

        if (i == n-1 && j == m-1)
            return (rem == mat[i][j]);

        if (dp[i][j][rem] != -1) return dp[i][j][rem];

        int ans = 0;
        if (i + 1 < n) ans += dfs(i + 1, j, mat, rem - mat[i][j], dp);
        if (j + 1 < m) ans += dfs(i, j + 1, mat, rem - mat[i][j], dp);

        return dp[i][j][rem] = ans;
    }

    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, -1)));
        return dfs(0, 0, mat, k, dp);
    }
};
