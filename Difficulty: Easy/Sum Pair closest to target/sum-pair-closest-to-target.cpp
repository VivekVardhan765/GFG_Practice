//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        if(n==1)return {};
        int l=0,r=n-1;
        int e1,e2;
        int diff=INT_MAX;
        while(l<r){
            int curr=arr[l]+arr[r];
            if(curr<target){
                if(abs(curr-target)<diff){
                    diff=abs(curr-target);
                    e1=arr[l];
                    e2=arr[r];
                }
                l++;
            }
            else{
                if(abs(curr-target)<diff){
                    diff=abs(curr-target);
                    e1=arr[l];
                    e2=arr[r];
                }
                r--;
            }
        }
        return {e1,e2};
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends