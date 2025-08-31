class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int l=0,r=n-1;
        int ans=0;
        while(l<r){
            int res=min(arr[l],arr[r])*(r-l);
            ans=max(res,ans);
            if(arr[l]>arr[r]){
                r--;
            }
            else l++;
        }
        return ans;
    }
};
