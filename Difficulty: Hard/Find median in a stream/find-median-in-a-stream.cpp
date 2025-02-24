//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<double>ans;
        ans.push_back(arr[0]);
        if(arr.size()==1){
            return ans;
        }
        priority_queue<int>l;
        priority_queue <int, vector<int>, greater<int>> r;
        l.push(min(arr[1],arr[0]));
        r.push(max(arr[1],arr[0]));
        ans.push_back((double(arr[1]+arr[0]))/2);
        for(int i=2;i<n;i++){
            if(arr[i]<r.top()){
                if(l.size()>r.size()){
                    int m=l.top();
                    l.pop();
                    l.push(min(m,arr[i]));
                    r.push(max(m,arr[i]));
                }
                else{
                    l.push(arr[i]);
                }
            }
            else{
                if(r.size()>l.size()){
                    int m=r.top();
                    r.pop();
                    l.push(min(m,arr[i]));
                    r.push(max(m,arr[i]));
                }
                else{
                    r.push(arr[i]);
                }
            }
            if(r.size()>l.size())ans.push_back(r.top());
            else if(r.size()<l.size())ans.push_back(l.top());
            else{
                ans.push_back(double(l.top()+r.top())/2);
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

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends