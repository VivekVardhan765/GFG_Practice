class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int n=arr.size();
        int minsu=INT_MAX;
        int maxu=INT_MIN;
        int mincurr=0;
        int maxcurr=0;
        int tot=0;
        for(int i=0;i<n;i++){
            mincurr+=arr[i];
            minsu=min(minsu,mincurr);
            if(mincurr>0)mincurr=0;
            maxcurr+=arr[i];
            maxu=max(maxu,maxcurr);
            if(maxcurr<0)maxcurr=0;
            tot+=arr[i];
        }
        if(maxu<0)return maxu;
        return max(maxu,tot-minsu);
        
    }
};