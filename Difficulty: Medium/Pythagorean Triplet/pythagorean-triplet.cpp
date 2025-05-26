class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int maxi=*max_element(arr.begin(),arr.end());
        vector<bool>vis(maxi+1);
        for(int el:arr){
            vis[el]=true;
        }
        for(int i=1;i<=maxi;i++){
            if(vis[i]){
                for(int j=1;j<=maxi;j++){
                    if(vis[j]){
                        int k=sqrt(i*i+j*j);
                        if((vis[k]) and k*k==i*i+j*j )return true;
                    }
                }
            }
        }
        return false;
        
    }
};