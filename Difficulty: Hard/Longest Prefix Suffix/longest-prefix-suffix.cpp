class Solution {
  public:
    int getLPSLength(string &s) {
        int n=s.size();
        int i=1;
        vector<int>lps(n,0);
        int l=0;
        while(i<n){
            if(s[i]==s[l]){
                l++;
                lps[i]=l;
                i++;
                
            }
            else{
                if(l==0){
                    lps[i]=0;
                    i++;
                }
                else{
                    l=lps[l-1];
                }
            }
        }
        return lps[n-1];
    }
};