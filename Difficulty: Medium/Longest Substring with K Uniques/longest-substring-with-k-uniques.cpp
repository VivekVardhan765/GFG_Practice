class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n=s.size();
        unordered_map<char,int>mpp;
        int l=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
            if(mpp.size()>k){
                ans=max(ans,i-l);
                mpp[s[l]]--;
                if(mpp[s[l]]==0)mpp.erase(s[l]);
                l++;
            }
        }
        if(mpp.size()==k)ans=max(ans,n-l);
        return ans;
        
    }
};