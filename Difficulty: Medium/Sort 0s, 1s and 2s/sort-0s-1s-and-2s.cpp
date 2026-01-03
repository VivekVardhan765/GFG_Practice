class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int r=n-1;
        for(int i=0;i<=r;i++){
            if(arr[i]==0){
                swap(arr[i],arr[l]);
                l++;
            }else if(arr[i]==2){
                swap(arr[i],arr[r]);
                r--;
                i--;
            }
        }
        return;
    }
};