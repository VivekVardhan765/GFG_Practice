class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        int n=s.size();
        int co=0,cc=0;
        for(char c:s){
            if(c=='(')co++;
            else {
                if(co)co--;
                else cc++;
            }
        }
        return co+cc;
    }
};