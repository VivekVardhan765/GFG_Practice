class Solution {
  public:
    int findPages(vector<int>& A, int M) 
    {
        //code here
        int N=A.size();
        if(M > N)
        return -1;
        int s=*max_element(A.begin(),A.end());
        int e=accumulate(A.begin(),A.end(),0);
        while(s<=e){
            int m=s+((e-s)/2);
            int sum=0;
            int count=1;
            int i=0;
            while(i<N){
                sum+=A[i];
                if(sum>m) count++,sum=A[i];
                i++;
            }
            if(count>M) s=m+1;
            else e=m-1;
        }
        return s;
    }
};