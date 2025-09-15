class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        int ans=0;
        int n=arr.size();
        unordered_set<string>sym={"+","-","/","*","^"};
        stack<int>st;
        for(int i=0;i<n;i++){
            if(sym.count(arr[i])){
                int e2=st.top();
                st.pop();
                int e1=st.top();
                st.pop();
                if(arr[i]=="+")st.push(e1+e2);
                else if(arr[i]=="-")st.push(e1-e2);
                else if(arr[i]=="*")st.push(e1*e2);
                else if(arr[i]=="/")st.push(floor((e1*1.0)/e2));
                else st.push(pow(e1,e2));
            }
            else st.push(stoi(arr[i]));
        }
        return st.top();
    }
};