class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // code here
        int n=arr.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                c++;
            }
        }
        if(c==0)return -1;
        int res=0;
        for(int i=0;i<c;i++){
            res+=arr[i];
        }
        int ans=c-res;
        for(int r=c;r<n;r++){
            res-=arr[r-c];
            res+=arr[r];
            ans=min(ans,c-res);
        }
        return ans;
    }
};