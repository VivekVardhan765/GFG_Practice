class Solution {
  public:
    string longestString(vector<string> &arr) {
        sort(arr.begin(), arr.end());
        unordered_set<string> valid;
        string res = "";
    
        for (const string& s : arr) {
            if (s.size() == 1 || valid.count(s.substr(0, s.size() - 1))) {
                valid.insert(s);
                if (s.size() > res.size() || (s.size() == res.size() && s < res)) {
                    res = s;
                }
            }
        }
    
        return res;
    }
};