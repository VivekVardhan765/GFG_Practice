class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int c=0;
        int l=0;
        int r=0;
        int ans=0;
        while(r<n){
            c+=(arr[r]+1)%2;
            if(c>k){
                ans=max(ans,r-l);
                if(arr[l]==0)c--;
                l++;
            }
            r++;
            
        }
        return max(ans,n-l);
        
    }
};
