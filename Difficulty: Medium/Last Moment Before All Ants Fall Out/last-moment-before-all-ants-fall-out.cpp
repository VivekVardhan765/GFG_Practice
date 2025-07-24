class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int mini=n;
        int maxi=0;
        for(int el:left)maxi=max(maxi,el);
        for(int el:right)mini=min(mini,el);
        return max(n-mini,maxi);
        
    }
};