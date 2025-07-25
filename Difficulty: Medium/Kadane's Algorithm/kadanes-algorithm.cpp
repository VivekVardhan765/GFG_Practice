class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int n=arr.size();
        int curr=0;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            curr+=arr[i];
            ans=max(ans,curr);
            if(curr<0)curr=0;
        }
        return ans;
    }
};