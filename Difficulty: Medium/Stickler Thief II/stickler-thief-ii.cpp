//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxValue(vector<int>& arr) {
        int n=arr.size();
        int p1=0,p2=0;
        for(int i=0;i<n-1;i++){
            int curr=max(p1,p2+arr[i]);
            p2=p1;
            p1=curr;
        }
        int ans=p1;
        p1=0,p2=0;
        for(int i=1;i<n;i++){
            int curr=max(p1,p2+arr[i]);
            p2=p1;
            p1=curr;
        }
        ans=max(p1,ans);
        return ans;
        
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends