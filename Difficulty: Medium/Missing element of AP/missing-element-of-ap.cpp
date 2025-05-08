//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        int n=arr.size();
        int l=0;
        int r=n-1;
        int d=min(arr[1]-arr[0],arr[2]-arr[1]);
        while(l<r){
            int mid=(l+r)/2;
            if((arr[r]-arr[mid])!=((r-mid)*d))l=mid+1;
            else r=mid;
        }
        if(l==0)return arr[n-1]+d;
        return arr[l]-d;
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
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends