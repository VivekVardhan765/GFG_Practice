class Solution {
  public:
    int f(int prev,int curr,vector<int>& arr,vector<vector<int>>& dp){
        if(curr==arr.size())return 0;
        if(dp[prev+1][curr]!=-1)return dp[prev+1][curr];
        if(prev==-1 or arr[curr]>arr[prev]){
            return dp[prev+1][curr]=max(1+f(curr,curr+1,arr,dp) , f(prev,curr+1,arr,dp));
        }
        else return dp[prev+1][curr]=f(prev,curr+1,arr,dp);
    }
    int lis(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(-1,0,arr,dp);
        
    }
};