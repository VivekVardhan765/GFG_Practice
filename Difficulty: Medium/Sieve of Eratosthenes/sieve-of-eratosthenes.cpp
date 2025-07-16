class Solution {
  public:
    vector<int> sieve(int n) {
        vector<bool>dp(n+1);
        dp[1]=true;
        dp[0]=true;
        for(int i=2;i*i<=n;i++){
            if(!dp[i]){
                for(int j=i*i;j<=n;j+=i){
                    dp[j]=true;
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<=n;i++){
            if(!dp[i])ans.push_back(i);
        }
        return ans;
        
    }
};