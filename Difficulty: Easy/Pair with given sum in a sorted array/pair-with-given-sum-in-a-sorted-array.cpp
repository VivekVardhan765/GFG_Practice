//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int n=arr.size();
        int l=0,r=n-1;
        int ans=0;
        while(l<r){
            if(arr[l]+arr[r]<target){
                l++;
            }
            else if(arr[l]+arr[r]>target){
                r--;
            }
            else {
                ans++;
                int curr_r=r;
                while( l<curr_r and arr[curr_r]==arr[curr_r-1]){
                    ans++;
                    curr_r--;
                }
                if(l==curr_r)ans--;
                l++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends