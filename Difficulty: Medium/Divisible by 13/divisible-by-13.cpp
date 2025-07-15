class Solution {
  public:
    
    bool divby13(string &s) {
        // code here
        int n=s.size();
        int curr=0;
        for(int i=0;i<n;i++){
            curr=((curr*10)+(s[i]-'0'))%13;
        }
        return curr==0;
        
    }
};