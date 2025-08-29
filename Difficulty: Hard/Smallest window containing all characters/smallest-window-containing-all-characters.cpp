class Solution {
  public:
    // Function to find the smallest window in the string s1 consisting
    // of all the characters of string s2.
    string smallestWindow(string &s, string &t) {
        int n=s.size();
        int m=t.size();
        unordered_map<char,int>mpp;
        for(char el:t)mpp[el]++;
        int start=-1;
        int len=INT_MAX;
        int track=0;
        int l=0;
        int r=0;
        while(r<n){
            if(mpp[s[r]]>0)track++;
            mpp[s[r]]--;
            while(track==m){
                if(r-l+1<len){
                    len=r-l+1;
                    start=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0)track--;
                l++;
            }
            r++;
        }
        if(start==-1)return "";
        return s.substr(start,len);
    }
};