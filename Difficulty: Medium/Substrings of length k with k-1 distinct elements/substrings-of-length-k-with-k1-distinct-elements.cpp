class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int n=s.size();
        int ans=0;
        vector<int>count(26,0);
        int res=0;
        for(int i=0;i<k;i++){
            if(count[int(s[i]-'a')]==0){
                res++;
            }
            count[int(s[i]-'a')]++;
        }
        if(res==k-1)ans++; 
        for(int i=k;i<n;i++){
            if(count[int(s[i]-'a')]==0){
                res++;
            }
            count[int(s[i]-'a')]++;
            count[int(s[i-k]-'a')]--;
            if(count[int(s[i-k]-'a')]==0){
                res--;
            }
            if(res==k-1)ans++; 
        }
        return ans;
    }
};