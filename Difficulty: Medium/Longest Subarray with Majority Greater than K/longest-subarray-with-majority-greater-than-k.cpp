class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mpp;
        int curr=0;
        int ans=0;
        mpp[0]=-1;
        for(int i=0;i<n;i++){
            if(arr[i]>k)curr++;
            else curr--;
            if (curr > 0)ans = i + 1;
            if(mpp.find(curr)==mpp.end())mpp[curr]=i;
            if (mpp.find(curr - 1) != mpp.end())ans = max(ans, i - mpp[curr - 1]);
            
        }
        return ans;
        
    }
};