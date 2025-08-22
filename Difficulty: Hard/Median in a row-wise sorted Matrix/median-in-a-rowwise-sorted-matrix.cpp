class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
        int l=INT_MAX,r=0;
        for(auto arr:mat){
            l=min(l,arr[0]);
            r=max(r,arr[m-1]);
        }
        int tot=n*m;
        int lim=(tot+1)/2;
        int ans=r;
        while(l<=r){
            int mid=(l+r)/2;
            int count=0;
            for(auto arr:mat){
                count+=(int)(upper_bound(arr.begin(),arr.end(),mid)-arr.begin());
            }
            if(count<lim){
                l=mid+1;
            }
            else{
                ans=mid;
                r=mid-1;
            }
            
        }
        return ans;
        
        
    }
};
