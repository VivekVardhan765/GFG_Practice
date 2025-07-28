class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans;
        int el1=-1,c1=0,el2=-1,c2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==el1)c1++;
            else if(arr[i]==el2)c2++;
            else if(c1==0){
                el1=arr[i];
                c1++;
            }
            else if(c2==0){
                el2=arr[i];
                c2++;
            }
            else {
                c1--;
                c2--;
            }
        }
        c1=0;
        c2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==el1)c1++;
            if(arr[i]==el2)c2++;
        }
        if(el1>el2){
            swap(el1,el2);
            swap(c1,c2);
        }
        if(c1>n/3)ans.push_back(el1);
        if(c2>n/3)ans.push_back(el2);
        return ans;
        
        
    }
};