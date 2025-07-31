class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& arr, int k) {
        int n=arr.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i][0]]++;
            mpp[arr[i][1]+1]--;
        }
        int ans=-1;
        int curr=0;
        for(auto [cp,c]:mpp){
            if(c<0 and curr>=k)ans=max(ans,cp-1);
            curr+=c;
        }
        return ans;
            
        
    }
};