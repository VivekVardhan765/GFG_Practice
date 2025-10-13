class Solution {
  public:
    int f(int curr,vector<vector<int>>& cost, int mask,vector<vector<int>>& dp){
        if(mask==0)return cost[curr][0];
        
        if(dp[curr][mask]!=-1)return dp[curr][mask];
        int n=cost.size();
        int ans=INT_MAX;
        
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                ans=min(ans,cost[curr][i]+f(i,cost,mask^(1<<i),dp));
            }
        }
        return dp[curr][mask]=ans;
        
    }
    int tsp(vector<vector<int>>& cost) {
        int n=cost.size();
        int mask=(1<<n)-1;
        vector<vector<int>>dp(n,vector<int>(mask,-1));
        mask^=1;
        return f(0,cost,mask,dp);
    }
};