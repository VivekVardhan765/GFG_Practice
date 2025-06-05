class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        int n1=s1.size();
        int n2=s2.size();
        int n3=s3.size();
        vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,0)));
        for(int i1=n1-1;i1>=0;i1--){
            for(int i2=n2-1;i2>=0;i2--){
                for(int i3=n3-1;i3>=0;i3--){
                    int curr=0;
                    if(s1[i1]==s2[i2] and s2[i2]==s3[i3]){
                        curr=1+dp[i1+1][i2+1][i3+1];
                    }
                    curr=max(curr,dp[i1+1][i2][i3]);
                    curr=max(curr,dp[i1][i2+1][i3]);
                    curr=max(curr,dp[i1][i2][i3+1]);
                    curr=max(curr,dp[i1+1][i2+1][i3]);
                    curr=max(curr,dp[i1][i2+1][i3+1]);
                    curr=max(curr,dp[i1+1][i2][i3+1]);
                    curr=max(curr,dp[i1+1][i2+1][i3+1]);
                    dp[i1][i2][i3]=curr;
                }
            }
        }
        return dp[0][0][0];
    }
};
