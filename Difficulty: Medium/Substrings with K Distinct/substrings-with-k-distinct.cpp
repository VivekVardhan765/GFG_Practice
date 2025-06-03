class Solution {
  public:
    int c(string& s, int k) {
        int n=s.size();
        vector<int>f(26,0);
        int i=0;
        int len=0;
        int ans=0;
        for(int j=0;j<n;j++){
            int curr=int(s[j]-'a');
            f[curr]++;
            if(f[curr]==1)len++;
            while(len>k){
                int prev=int(s[i]-'a');
                f[prev]--;
                if(f[prev]==0)len--;
                i++;
            }
            ans += j - i + 1;
        }
        return ans;
    }
    int countSubstr(string& s, int k) {
        return c(s,k)-c(s,k-1);
    }
};