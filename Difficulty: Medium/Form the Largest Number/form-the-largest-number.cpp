class Solution {
  public:
    string findLargest(vector<int> &arr) {
        sort(arr.begin(),arr.end(),[](int a,int b){
            return to_string(a)+to_string(b)>to_string(b)+to_string(a);
        });
        if(arr[0]==0)return "0";
        string ans="";
        int tot=0;
        for(auto it:arr){
            ans+=to_string(it);
        }
        return ans;
    }
};