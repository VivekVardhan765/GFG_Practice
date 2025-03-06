//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int i1,int i2,string& s1,string& s2,vector<vector<int>>& dp){
        if(i1==s1.size() or i2==s2.size())return 0;
        int res=INT_MIN;
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        if(s1[i1]==s2[i2]){
            res=max(res,1+f(i1+1,i2+1,s1,s2,dp));
        }
        res=max(res,f(i1,i2+1,s1,s2,dp));
        res=max(res,f(i1+1,i2,s1,s2,dp));
        return dp[i1][i2]=res;
    }
    int lcs(string &s1, string &s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,s1,s2,dp);
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends