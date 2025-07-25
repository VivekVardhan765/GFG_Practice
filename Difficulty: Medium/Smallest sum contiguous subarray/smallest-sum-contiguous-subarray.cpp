// User function Template for C++

class Solution {
  public:
    int smallestSumSubarray(vector<int>& arr) {
        // Code here
        int n=arr.size();
        int ans=INT_MAX;
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=arr[i];
            ans=min(ans,curr);
            if(curr>0)curr=0;
        }
        return ans;
    }
};
