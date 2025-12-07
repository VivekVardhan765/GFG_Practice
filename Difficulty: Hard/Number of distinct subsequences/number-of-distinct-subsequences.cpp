class Solution {
  public:
    int distinctSubseq(string &s) {
        int n=s.size();
        long long int mod=1e9+7;
        vector<int>dp(26,0);
        int ans=1;
        for(int i=0;i<n;i++){
            int prev=ans;
            ans=(ans*2)%mod;
            ans=(ans-dp[s[i]-'a']+mod)%mod;
            dp[s[i]-'a']=prev;
        }
        return ans;
        
    }
};