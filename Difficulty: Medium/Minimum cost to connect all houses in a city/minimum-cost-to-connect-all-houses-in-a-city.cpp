//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class DSU{
    public:
    vector<int>parent,rank;
    DSU(int n){
        parent.resize(n,-1);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int i){
        if(parent[i]==i){
            return i;
        }
        return parent[i]=find(parent[i]);
    }
    void unite(int x,int y){
        int px=find(x);
        int py=find(y);
        if(rank[px]==rank[py]){
            parent[py]=px;
            rank[px]++;
        }
        else if(rank[px]<rank[py]){
            parent[px]=py;
        }
        else parent[py]=px;
    }
};
class graph{
    public:
    vector<vector<int>>edges;
    int n;
    graph(int n){
        this->n=n;
    }
    void add(int x,int y,int w){
        edges.push_back({w,x,y});
    }
    int msum(){
        sort(edges.begin(),edges.end());
        DSU dsu(edges.size());
        int ans=0;
        int count=0;
        for(auto edge:edges){
            int w=edge[0];
            int x=edge[1];
            int y=edge[2];
            if(dsu.find(x)!=dsu.find(y)){
                dsu.unite(x,y);
                ans+=w;
                count++;
            }
            if(count==n-1)break;
        }
        return ans;
    }
    
};
class Solution {
  public:
    int minCost(vector<vector<int>>& h) {
        int n=h.size();
        graph g(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int c=abs(h[i][0]-h[j][0])+abs(h[j][1]-h[i][1]);
                g.add(i,j,c);
            }
        }
        return g.msum();
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends