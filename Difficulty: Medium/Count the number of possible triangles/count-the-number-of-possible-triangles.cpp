class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=n-1;i>=0;i--){
            int s1=arr[i];
            int l=0;
            int r=i-1;
            while(l<r){
                if(arr[r]+arr[l]>s1){
                    ans+=(r-l);
                    r--;
                }
                else l++;
            }
        }
        return ans;
    }
};
