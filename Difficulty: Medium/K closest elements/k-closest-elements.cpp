class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        int r=arr.size()-1;
        int n=arr.size();
        vector<int>ans;
        int l=0;
        while(l<=r){
            int mid=(r+l)/2;
            if(arr[mid]>x){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        int rb=l;
        int lb=rb-1;
        while (lb >= 0 && arr[lb] == x) lb--;
        while((rb<n and lb>-1) and k>0){
            int rd=abs(arr[rb]-x);
            int ld=abs(arr[lb]-x);
            if(ld<rd){
                ans.push_back(arr[lb]);
                lb--;
            }
            else{
                ans.push_back(arr[rb]);
                rb++;
            }
            k--;
        }
        while(rb<n and k>0){
            ans.push_back(arr[rb]);
            rb++;
            k--;
        }
        while(lb>=0 and k>0){
            ans.push_back(arr[lb]);
            lb--;
            k--;
        }
        return ans;
    }
};