class Solution {
  public:
    int lcmTriplets(int n) {
        // code here
        if(n==1)return 1;
        if(n==2)return 2;
        if(n%2==0 and n%3==0)return (n-3)*(n-1)*(n-2);
        if(n%2==0)return n*(n-1)*(n-3);
        return n*(n-1)*(n-2);
    }
};