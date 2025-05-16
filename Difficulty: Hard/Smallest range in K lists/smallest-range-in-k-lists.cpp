//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int k=arr.size();
        int n=arr[0].size();
        vector<int>k_ind(k,0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        int hval=-1;
        int a=-1;
        int b=-1;
        for(int i=0;i<k;i++){
            pq.push({arr[i][0],i});
            hval=max(hval,arr[i][0]);
            
        }
        int maxind=-1;
        int dist=INT_MAX;
        while(true){
            int y=pq.top().second;
            int lval=pq.top().first;
            int cdist=hval-lval;
            if(cdist<dist){
                a=lval;
                b=hval;
                dist=cdist;
            }
            pq.pop();
            int x=++k_ind[y];
            if (k_ind[y] == n) break;
            maxind=max(x,maxind);
            hval=max(hval,arr[y][x]);
            pq.push({arr[y][x],y});
        }
        return {a,b};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends