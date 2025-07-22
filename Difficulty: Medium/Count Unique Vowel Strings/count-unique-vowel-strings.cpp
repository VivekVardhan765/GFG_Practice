class Solution {
  public:
    int vowelCount(string& s) {
        // code here
        unordered_set<char>st={'a','e','i','o','u'};
        unordered_map<char,int>mpp;
        for(auto it:s){
            if(st.find(it)!=st.end())mpp[it]++;
        }
        int n=mpp.size();
        if(n==0)return 0;
        int ans=1;
        for(auto it:mpp){
            ans*=it.second;
        }
        for(int i=1;i<=n;i++){
            ans*=i;
        }
        return ans;
    }
};