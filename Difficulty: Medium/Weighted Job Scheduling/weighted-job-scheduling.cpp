class Solution {
  public:
    int maxProfit(vector<vector<int>> &jobs) {
        int n = jobs.size();
        
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        
        unordered_map<int, int> mpp;
        mpp[0] = 0;
        
        vector<int> arr = {0};
        for (int i = 0; i < n; i++) arr.push_back(jobs[i][1]);
        
        for (int i = 0; i < n; i++) {
            int start = jobs[i][0];
            int end = jobs[i][1];
            int profit = jobs[i][2];
            
            int idx = upper_bound(arr.begin(), arr.end(), start) - arr.begin() - 1;
            int prevEnd = arr[idx];
            
            int include = mpp[prevEnd] + profit;
            
            int prev;
            if (i > 0) {
                prev = mpp[arr[i]];  
            } else {
                prev = 0;             
            }
            
            mpp[end] = max(include, prev);
        }
        
        return mpp[jobs[n - 1][1]];
    }
};
