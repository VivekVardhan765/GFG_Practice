class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int n=a1.size();
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int sum1=0;
        int sum2=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum2+=a2[i];
            sum1+=a1[i];
            int diff=sum2-sum1;
            if(mpp.find(diff)==mpp.end()){
                mpp[diff]=i;
            }
            else{
                ans=max(ans,i-mpp[diff]);
            }
        }
        return ans;
    }
};