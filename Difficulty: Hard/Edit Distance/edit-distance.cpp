//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int i1,int i2,string& s1, string& s2,vector<vector<int>>& dp){
        if(i1==s1.size())return s2.size()-i2;
        if(i2==s2.size())return s1.size()-i1;
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        if(s1[i1]==s2[i2])return dp[i1][i2]=f(i1+1,i2+1,s1,s2,dp);
        else{
            int ans=INT_MAX;
            ans=min(ans,1+f(i1+1,i2,s1,s2,dp));
            ans=min(ans,1+f(i1,i2+1,s1,s2,dp));
            ans=min(ans,1+f(i1+1,i2+1,s1,s2,dp));
            return dp[i1][i2]=ans;
        }
    }
    int editDistance(string& s1, string& s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1)); 
        return f(0,0,s1,s2,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends