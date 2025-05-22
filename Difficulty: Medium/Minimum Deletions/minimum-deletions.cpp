class Solution {
  public:
    int f(int i1,int i2,string& s1,string& s2,vector<vector<int>>& dp){
        if(i1==s1.size() or i2==s2.size())return 0;
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        int ans=INT_MIN;
        ans=max(ans,f(i1+1,i2,s1,s2,dp));
        ans=max(ans,f(i1,i2+1,s1,s2,dp));
        if(s1[i1]==s2[i2])ans=max(ans,1+f(i1+1,i2+1,s1,s2,dp));
        return dp[i1][i2]=ans;
    }
    int minDeletions(string s) {
        // code here
        int n=s.size();
        string t=s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return n-f(0,0,s,t,dp);
        
    }
};