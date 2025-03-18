//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool f(int ind,int tar,vector<int>& arr,vector<vector<int>>& dp){
        if(ind>=arr.size() or tar<0)return false;
        if(tar==0 or tar==arr[ind])return true;
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        bool pick=f(ind+1,tar-arr[ind],arr,dp);
        bool npick=f(ind+1,tar,arr,dp);
        return dp[ind][tar] = (pick or npick);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return f(0,sum,arr,dp);
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends