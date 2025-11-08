class Solution {
  public:
    int numberOfWays(int n) {
        // code here
        int i1=1;
        int i2=2;
        for(int i=1;i<n;i++){
            int temp=i2;
            i2=i1+i2;
            i1=temp;
        }
        return i1;
    }
};