//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n=arr.size();
        int product=1;
        int c=0;
        for(int el:arr){
            if(el==0)c++;
            else product*=el;
        }
        for(int i=0;i<n;i++){
            if(c==0){
                arr[i]=product/arr[i];
            }
            else if(c==1){
                if(arr[i]!=0)arr[i]=0;
                else arr[i]=product;
            }
            else{
                arr[i]=0;
            }
        }
        return arr;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends