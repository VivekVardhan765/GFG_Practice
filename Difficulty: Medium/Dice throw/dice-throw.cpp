class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        vector <int> prev(x + 1, 0);
        prev[0] = 1;
        
        for(int i = 1; i <= n; i++){
            vector <int> curr(x+1);
            for(int sum = 0; sum <= x; sum++){
                for(int face = 1; face <= m; face++){
                    if(sum-face >= 0){
                        curr[sum] = curr[sum] + prev[sum - face];
                    }
                }
            }
            
            prev = curr;
        }
        
        return prev[x];
    }
};