class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        string s1="",s2="";
        for(int i=n-1;i>=0;i--){
            if(i%2==0){
                if(s1.size()==0 and arr[i]==0){
                    continue;
                }
                else{
                    s1+=char('0'+arr[i]);
                }
            }
            else{
                if(s2.size()==0 and arr[i]==0){
                    continue;
                }
                else{
                    s2+=char('0'+arr[i]);
                }
            }
        }
        int carr=0;
        int n1=s1.size();
        int n2=s2.size();
        int i=0;
        string ans="";
        while(i<n1 and i<n2){
            int curr1=int(s1[i]-'0');
            int curr2=int(s2[i]-'0');
            int tot=carr+curr1+curr2;
            carr=tot/10;
            tot=tot%10;
            ans+=char('0'+tot);
            i++;
        }
        if(i<n1){
            int curr1=int(s1[i]-'0');
            int tot=carr+curr1;
            carr=tot/10;
            tot=tot%10;
            ans+=char('0'+tot);
        }
        if(i<n2){
            int curr2=int(s2[i]-'0');
            int tot=carr+curr2;
            carr=tot/10;
            tot=tot%10;
            ans+=char('0'+tot);
        }
        if(carr!=0)ans+='1';
        while(ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
        
    }
};