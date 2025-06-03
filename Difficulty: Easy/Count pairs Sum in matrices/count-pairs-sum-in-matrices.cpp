class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int n=mat1.size();
        int m=n;
        int l=0;
        int r=(n*m)-1;
        int ans=0;
        while(l<(n*m) and r>=0){
            int lx=l%m;
            int ly=l/m;
            int rx=r%m;
            int ry=r/m;
            if(mat1[ly][lx]+mat2[ry][rx]<x){
                l++;
            }
            else{
                if(mat1[ly][lx]+mat2[ry][rx]==x)ans++;
                r--;
            }
        }
        return ans;
    }
};