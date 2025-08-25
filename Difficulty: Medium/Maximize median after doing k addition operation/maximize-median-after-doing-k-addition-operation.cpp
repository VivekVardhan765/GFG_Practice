class Solution {
  public:
    int maximizeMedian(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int i=(n-1)/2;
        int r=i+1;
        int val=arr[i];
        while(r<n){
            int rem= (arr[r]-val)*(r-i);
            if(k>=rem){
                val=arr[r];
                //  cout<<"current val="<<val<<" "<< "k changed from" << k;
                k-=rem;
                // cout<<" "<< "to "<<k<< endl;
                r++;
            }
            else{
                val+=k/(r-i);
                if(r-i ==1 and n%2==0)return (arr[i]+arr[r]+k)/2;
                return val;
            }
        }
        val+=k/(r-i);
        return val;
        
    }
};