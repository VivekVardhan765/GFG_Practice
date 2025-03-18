//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int n=arr.size();
        int tot=accumulate(arr.begin(),arr.end(),0);
        if(tot%2)return 0;
        tot=tot/2;
        vector<vector<bool>>dp(n,vector<bool>(tot+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        dp[0][arr[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=tot;j++){
                dp[i][j]=dp[i-1][j];
                if(j-arr[i]>=0){
                    dp[i][j]=(dp[i][j] or dp[i-1][j-arr[i]]);
                }
            }
        }
        return dp[n-1][tot];
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends