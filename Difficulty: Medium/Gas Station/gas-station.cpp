class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int n=gas.size();
        vector<int>pre(n+1,0);
        int mini=INT_MAX;
        int minind=-1;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+gas[i-1]-cost[i-1];
            if(pre[i]<mini){
                minind=i;
                mini=pre[i];
            }
        }
        if(pre[n]<0)return -1;
        return minind%n;
        
    }
};