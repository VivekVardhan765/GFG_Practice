class Solution {
  public:
    long long eval(const string &s, bool &ok) {
        ok = true;
        vector<long long> nums;
        vector<char> ops;
        long long num = 0;
    
        for (int i = 0; i < s.size();) {
            if (!isdigit(s[i])) {
                ops.push_back(s[i]);
                i++;
                continue;
            }
            int j = i;
            while (j < s.size() && isdigit(s[j])) j++;
            string sub = s.substr(i, j - i);
            if (sub.size() > 1 && sub[0] == '0') {
                ok = false;
                return 0;
            }
            num = stoll(sub);
            if (!ops.empty() && ops.back() == '*') {
                ops.pop_back();
                long long prev = nums.back();
                nums.pop_back();
                nums.push_back(prev * num);
            } else nums.push_back(num);
            i = j;
        }
    
        long long res = nums[0];
        int idx = 1;
        for (char op : ops) {
            if (op == '+') res += nums[idx++];
            else if (op == '-') res -= nums[idx++];
        }
        return res;
    }
    
    void backtrack(int ind, string &s, string curr, vector<string>& ans, int target) {
        if (ind == s.size()) {
            bool ok;
            long long val = eval(curr, ok);
            if (ok && val == target)
                ans.push_back(curr);
            return;
        }
        curr.push_back(s[ind]);
        if (ind != s.size() - 1) {
            backtrack(ind + 1, s, curr + "+", ans, target);
            backtrack(ind + 1, s, curr + "-", ans, target);
            backtrack(ind + 1, s, curr + "*", ans, target);
            backtrack(ind + 1, s, curr, ans, target);
        } else {
            backtrack(ind + 1, s, curr, ans, target);
        }
    }
    
    vector<string> findExpr(string &s, int target) {
        vector<string> ans;
        backtrack(0, s, "", ans, target);
        sort(ans.begin(), ans.end());
        return ans;
    }
};