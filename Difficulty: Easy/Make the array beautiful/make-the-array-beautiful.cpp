class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(st.empty())st.push(arr[i]);
            else{
                if(arr[i]*st.top()<=0 and (arr[i]<0 or st.top()<0))st.pop();
                else st.push(arr[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};