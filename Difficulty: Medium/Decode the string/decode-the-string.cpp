class Solution {
  public:
    string f(string &s, int &i) {
        string result = "";
        while (i < s.size() && s[i] != ']') {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i++;
                string inside = f(s, i);
                i++;
                while (num--) result += inside;
            } else {
                result += s[i];
                i++;
            }
        }
        return result;
    }
    
    string decodedString(string &s) {
        int i = 0;
        return f(s, i);
    }
};