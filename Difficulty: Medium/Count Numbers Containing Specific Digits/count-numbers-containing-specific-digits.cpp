class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
        int tot=9;
        for(int i=2;i<=n;i++)tot*=10;
        unordered_set<int>st(arr.begin(),arr.end());
        int count=st.size();
        int neg=9-count;
        if(st.find(0)!=st.end())neg++;
        for(int i=2;i<=n;i++)neg*=(10-count);
        return tot-neg;
    }
};
