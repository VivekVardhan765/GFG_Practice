class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() and (mpp[arr[st.top()]] < mpp[arr[i]])){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);

        }
        return ans;
    }
};
