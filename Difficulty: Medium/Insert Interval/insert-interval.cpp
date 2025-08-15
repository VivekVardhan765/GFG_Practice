class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &arr, vector<int> &ni) {
        vector<vector<int>> ans;
        int n = arr.size();
        int i = 0;
    
        while (i < n && arr[i][1] < ni[0]) {
            ans.push_back(arr[i]);
            i++;
        }
    
        int start = (i < n) ? min(ni[0], arr[i][0]) : ni[0];
    
        while (i < n && arr[i][0] <= ni[1]) {
            i++;
        }
        int end;
        if (i == 0 || arr[i - 1][0] > ni[1]) {
            end = ni[1];
        } else {
            end = max(ni[1], arr[i - 1][1]);
        }
        ans.push_back({start, end});
            while (i < n) {
            ans.push_back(arr[i]);
            i++;
        }
    
        return ans;
    }

};