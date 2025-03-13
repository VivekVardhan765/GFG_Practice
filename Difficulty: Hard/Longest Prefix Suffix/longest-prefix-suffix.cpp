//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function template for C++

class Solution {
  public:
    int longestPrefixSuffix(string &s) {
        int n=s.size();
        vector<int>lps(n,0);
        int i=1;
        int l=0;
        while(i<n){
            if(s[i]==s[l]){
                lps[i]=++l;
                i++;
                
            }
            else{
                if(l==0){
                    lps[i]=0;
                    i++;
                }
                else{
                    l=lps[l-1];
                }
            }
        }
        return lps[n-1];
        
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.longestPrefixSuffix(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends