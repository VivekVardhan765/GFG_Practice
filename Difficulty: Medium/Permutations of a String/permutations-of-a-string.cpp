//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void f(string& s,string& v,unordered_set<string>& st,vector<bool>& vis){
        int n=s.size();
        if(v.size()==vis.size()){
            st.insert(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                string p=v;
                v+=s[i];
                vis[i]=true;
                f(s,v,st,vis);
                v=p;
                vis[i]=false;
            }
        }
    }
    vector<string> findPermutation(string &s) {
        int n=s.size();
        vector<bool>vis(n,false);
        string v="";
        unordered_set<string>st;
        f(s,v,st,vis);
        vector<string>ans(st.begin(),st.end());
        return ans;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends