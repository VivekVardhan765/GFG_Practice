class Solution {
  public:
  void dperm(int ind, vector<int>& arr, vector<vector<int>>& ans) {
    if (ind == arr.size()) {
        ans.push_back(arr);
        return;
    }
    unordered_set<int> used; 
    for (int i = ind; i < arr.size(); i++) {
        if (used.count(arr[i])) continue; 
        used.insert(arr[i]);
        swap(arr[ind], arr[i]);
        dperm(ind + 1, arr, ans);
        swap(arr[ind], arr[i]);
    }
}

vector<vector<int>> uniquePerms(vector<int>& arr) {
    vector<vector<int>> ans;
    dperm(0, arr, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

};