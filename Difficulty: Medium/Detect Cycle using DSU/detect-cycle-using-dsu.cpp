//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int find(int a,vector<int>& parent){
        if(parent[a]==a)return a;
        return parent[a]=find(parent[a],parent);
    }
    void Union(int a,int b,vector<int>& parent,vector<int>& rank){
        int pa=find(a,parent);
        int pb=find(b,parent);
        if(rank[pa]==rank[pb]){
            parent[pb]=pa;
            rank[pa]++;
        }
        else{
            if(rank[pa]>rank[pb]){
            parent[pb]=pa;
            }
            else parent[pa]=pb;
        }
    }
	int detectCycle(int n, vector<int>adj[])
	{
	    vector<int>parent(n),rank(n,0);
	    for(int i=0;i<n;i++){
	        parent[i]=i;
	    }
	    for(int i=0;i<n;i++){
	        for(int el:adj[i]){
	            if(el>i){
	                if(find(el,parent)==find(i,parent)){
	                    return true;
	                }
	                else{
	                    Union(i,el,parent,rank);
	                }
	            }
	        }
	    }
	    return false;
	    
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends