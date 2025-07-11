class Solution {
  public:
    int countConsec(int n) {
        int p0=1,p1=1;
        for(int i=2;i<=n;i++){
            int c0=p0+p1;
            int c1=p0;
            p1=c1;
            p0=c0;
        }
        return (1<<n)-(p1+p0);
    }
};