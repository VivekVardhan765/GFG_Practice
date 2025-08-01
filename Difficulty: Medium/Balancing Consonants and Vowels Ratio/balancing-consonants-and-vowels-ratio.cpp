class Solution {
  public:
    int diff(string& s){
        int n=s.size();
        int count=0;
        unordered_set<char>st={'a','e','i','o','u'};
        for(int i=0;i<n;i++){
            if(st.find(s[i])!=st.end())count++;
        }
        return 2*count - n;
    }
    int countBalanced(vector<string>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=diff(arr[i]);
            ans+=mpp[sum];
            mpp[sum]++;
        }
        return ans;
        
    }
};