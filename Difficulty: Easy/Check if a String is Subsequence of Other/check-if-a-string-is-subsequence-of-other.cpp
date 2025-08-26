class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int n1=s1.size();
        int n2=s2.size();
        int i1=0,i2=0;
        while(i1<n1 and i2<n2){
            if(s1[i1]==s2[i2])i1++;
            i2++;
        }
        if(i1==n1)return true;
        return false;
    }
};