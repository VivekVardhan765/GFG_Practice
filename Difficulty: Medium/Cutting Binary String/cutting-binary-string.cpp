class Solution {
  public:
    bool check(int val){
        while(val%5==0){
            val=val/5;
        }
        return val==1;
    }
    int f(int ind,string& s){
        if(ind==s.size())return 0;
        int ans=1e9-30;
        if(s[ind]!='0'){
            int val=0;
            for(int i=ind;i<s.size();i++){
                val=(val*2)+(s[i]-'0');
                if(check(val)){
                    ans=min(ans,1+f(i+1,s));
                }
            }
        }
        return ans;
        
    }
    int cuts(string s) {
        // code here
        int ans= f(0,s);
        if(ans==1e9-30)return -1;
        else return ans;
    }
};