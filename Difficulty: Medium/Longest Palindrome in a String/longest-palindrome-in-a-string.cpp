//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string &s) {
        int n = s.size();
        if (n == 0) return "";
        string res = "";
        for (int i = 0; i < n; i++) {
            string odd = expandAroundCenter(s, i, i);
            string even = expandAroundCenter(s, i, i + 1);
            if (odd.size() > res.size()) res = odd;
            if (even.size() > res.size()) res = even;
        }
        return res;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends