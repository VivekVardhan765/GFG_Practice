class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<k;i++){
            mpp[arr[i]]++;
        }
        set<pair<int,int>>pq;
        for(auto [a,b]:mpp){
            pq.emplace(b,-a);
        }
        int r=k;
        int l=0;
        int ans=0;
        while(r<n){
            ans+=-(*pq.rbegin()).second;
            pq.erase({mpp[arr[l]],-arr[l]});
            mpp[arr[l]]--;
            pq.emplace(mpp[arr[l]],-arr[l]);
            pq.erase({mpp[arr[r]],-arr[r]});
            mpp[arr[r]]++;
            pq.emplace(mpp[arr[r]],-arr[r]);
            r++;
            l++;
            
        }
        ans+=-(*pq.rbegin()).second;
        return ans;
        
    }
};