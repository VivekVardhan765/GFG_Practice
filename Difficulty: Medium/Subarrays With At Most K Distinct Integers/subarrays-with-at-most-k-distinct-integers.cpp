class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int l=0;
        int ans=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
            while(mpp.size()>k){
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0)mpp.erase(arr[l]);
                l++;
            }
            ans+=i-l+1;
        }
        return ans;
        
    }
};