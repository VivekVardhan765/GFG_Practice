class Solution {
  public:
    void bstrings(int n,string& cont,vector<string>& ans){
        if(n==0){
            ans.push_back(cont);
        }
        else{
            cont+='0';
            bstrings(n-1,cont,ans);
            cont.pop_back();
            cont+='1';
            bstrings(n-1,cont,ans);
            cont.pop_back();

        }
        
    }
    vector<string> binstr(int n) {
        // code here
        string cont="";
        vector<string>ans;
        bstrings(n,cont,ans);
        return ans;
    }
};