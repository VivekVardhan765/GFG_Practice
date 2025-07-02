class Solution {
  public:
    int totalElements(vector<int> &arr) {
        unordered_map<int,int>mpp;
        int l=0;
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
            if(mpp.size()>2){
                ans=max(ans,i-l);
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0)mpp.erase(arr[l]);
                l++;
            }
        }
        return max(ans,n-l);
    }

};