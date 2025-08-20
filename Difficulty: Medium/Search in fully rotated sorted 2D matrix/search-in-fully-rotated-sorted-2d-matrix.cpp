class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int target) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int l = 0, r = n*m - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            int row = mid / m;
            int col = mid % m;
            int val = mat[row][col];

            if (val == target) return true;

            // Get l and r values in matrix form
            int lval = mat[l/m][l%m];
            int rval = mat[r/m][r%m];

            if (lval <= val) {
                // Left half is sorted
                if (lval <= target && target < val) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                // Right half is sorted
                if (val < target && target <= rval) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};
