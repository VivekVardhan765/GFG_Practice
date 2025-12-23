class Solution {
  public:
    int ub(int a,vector<int>& arr){
        int r=arr.size();
        int l=0;
        while(l<r){
            int mid=(l+r)/2;
            if(arr[mid]<=a){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return l;
    }
    int lb(int a,vector<int>& arr){
        int r=arr.size();
        int l=0;
        while(l<r){
            int mid=(l+r)/2;
            if(arr[mid]>=a){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int m=queries.size();
        vector<int>ans;
        for(auto q: queries){
            int l=q[0];
            int r=q[1];
            ans.push_back(ub(r,arr)-lb(l,arr));
        }
        return ans;
        
    }
};