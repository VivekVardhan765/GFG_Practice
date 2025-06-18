class Solution {
  public:
    int f(vector<int>&arr,int d){
        int n=arr.size();
        int val=0;
        for(int i=0;i<n;i++){
            val+=((arr[i]+d-1)/d);
        }
        return val;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        int r=*max_element(arr.begin(),arr.end());
        int l=1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(f(arr,mid)<=k){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
        
    }
};
