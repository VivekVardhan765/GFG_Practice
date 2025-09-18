class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        int n=arr.size();
        stack<int>st;
        vector<int>ind(n,-1);
        for(int i1=0;i1<2*n;i1++){
            int i=i1%n;
            while(!st.empty() and arr[i]>arr[st.top()]){
                ind[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if(ind[i]!=-1)ind[i]=arr[ind[i]];
            
        }
        return ind;
    }
};