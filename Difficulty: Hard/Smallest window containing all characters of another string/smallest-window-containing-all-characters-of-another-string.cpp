class Solution {
  public:
    // Function to find the smallest window in the string s1 consisting
    // of all the characters of string s2.
    string smallestWindow(string &s, string &t) {
        // Your code here
        int m=t.size();
        int n=s.size();
        unordered_map<char,int>mpp;
        for(auto el:t){
            mpp[el]++;
        }
        int l=0;
        int lind=-1;
        int len=1e9+7;
        int c=0;
        for(int i=0;i<n;i++){
            mpp[s[i]]--;
            if(mpp[s[i]]>=0)c++;
            while(c==m){
                if(i-l+1<len){
                    len=i-l+1;
                    lind=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0){
                    c--;
                }
                l++;
            }
        }
        if(lind==-1)return "";
        return s.substr(lind,len);
        
    }
};