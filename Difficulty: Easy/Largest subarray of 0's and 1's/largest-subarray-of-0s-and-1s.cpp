//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n=arr.size();
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int c1=0;
        int c0=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1)c1++;
            else c0++;
            if(mpp.find(c1-c0)==mpp.end()){
                mpp[c1-c0]=i;
            }
            else{
                ans=max(ans,i-mpp[c1-c0]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends