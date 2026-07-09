class Solution {
  public:
    int getCount(int n) {
        int ans=0;
        if (n==1 or n==2)return 0;
        for(int i=2;i*i+i<=2*n;i++){
            int csum=(i*(i+1))/2;
            if((n-csum==0) or ((n-csum)%i==0))ans++;
        }
        return ans;
        
    }
};