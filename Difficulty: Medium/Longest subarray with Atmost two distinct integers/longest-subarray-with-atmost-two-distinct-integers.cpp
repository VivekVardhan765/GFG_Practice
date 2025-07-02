class Solution {
  public:
    int totalElements(vector<int> &arr) {
        unordered_map<int, int> freq;
        int left = 0, right = 0, maxLen = 0;
        while (right < arr.size()) {
            freq[arr[right]]++;
            while (freq.size() > 2) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0)
                    freq.erase(arr[left]);
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
    
        return maxLen;
    }

};