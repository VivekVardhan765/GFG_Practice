class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int ans=arr[0]+arr[1];
        int n=arr.size();
        for(int i=2;i<n;i++){
            ans=max(ans,arr[i]+arr[i-1]);
        }
        return ans;
    }
};