//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int ind,int k,int b,vector<int>& arr,vector<vector<vector<int>>>& dp){
        if(ind>=arr.size())return 0;
        if(k==0 and b==1)return 0;
        if(dp[ind][k][b]!=-1)return dp[ind][k][b];
        if(b==1){
            int buy=-arr[ind]+f(ind+1,k,0,arr,dp);
            int sbuy=f(ind+1,k,1,arr,dp);
            return dp[ind][k][b]=max(buy,sbuy);
        }
        else{
            int sell=arr[ind]+f(ind+1,k-1,1,arr,dp);
            int ssell=f(ind+1,k,0,arr,dp);
            return dp[ind][k][b]=max(sell,ssell);
        }
    }
    int maxProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return f(0,k,1,prices,dp);
        
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends