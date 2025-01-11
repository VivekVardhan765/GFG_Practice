//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        unordered_map<char, int> lastIndex;
        int n = s.size();
        int ans = 0, start = 0;
    
        for (int i = 0; i < n; i++) {
            if (lastIndex.find(s[i]) != lastIndex.end() && lastIndex[s[i]] >= start) {
                start = lastIndex[s[i]] + 1;
            }
            lastIndex[s[i]] = i;
            ans = max(ans, i - start + 1);
        }
    
        return ans;
    }

};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends