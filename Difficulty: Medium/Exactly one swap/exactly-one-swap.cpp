class Solution {
  public:
    int countStrings(string &s) {
        // code here
        int n=s.size();
        vector<int>f(26);
        for(char el:s){
            f[int(el-'a')]++;
            
        }
        int ans=0;
        int extra=0;
        for(int i=0;i<26;i++){
            if(f[i]>1)extra=1;
            ans+=f[i]*(n-f[i]);
        }
        return extra+(ans/2);
    }
};
