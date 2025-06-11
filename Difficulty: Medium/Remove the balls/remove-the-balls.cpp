class Solution {
  public:
    int findLength(vector<int> &c, vector<int> &r) {
        // code here
        int n=c.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!st.empty()){
                int a=st.top();
                if(c[a]==c[i] and r[a]==r[i])st.pop();
                else st.push(i);
            }
            else st.push(i);
        }
        return st.size();
    }
};