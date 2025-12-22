// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        int m=arr[0].size();
        int ans=-1;
        int preval=-1;
        for(int i=0;i<n;i++){
            int l=0;
            int r=arr[0].size();
            while(l<=r){
                int mid=l+(r-l)/2;
                if(arr[i][mid]==1){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            if(m-r>preval){
                ans=i;
                preval=m-r;
            }
        }
        return ans;
    }
};