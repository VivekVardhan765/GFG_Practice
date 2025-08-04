class Solution {
  public:
    
    // Kadane's algorithm to find the maximum sum 
    // subarray in a 1D array
    int kadane(vector<int>& temp) {
      	int rows = temp.size();
        int currSum = 0;
        int maxSum = INT_MIN;
    
        for (int i = 0; i < rows; i++) {
            currSum += temp[i];
    
            // Update maxSum if the current sum is greater
            if (maxSum < currSum) {
                maxSum = currSum;
            }
    
            // If the current sum becomes negative, reset it to 0
            if (currSum < 0) {
                currSum = 0;
            }
        }
    
        return maxSum;
    }
    
    // Function to find the maximum sum rectangle in a 2D matrix
    int maxRectSum(vector<vector<int>> &mat) {
        int rows = mat.size();
        int cols = mat[0].size();
    
        int maxSum = INT_MIN;
    
        // Initialize a temporary array to store row-wise
      	// sums between left and right boundaries
        vector<int> temp(rows);
    
        // Check for all possible left and right boundaries
        for (int left = 0; left < cols; left++) {
          
            // Reset the temporary array for each new left boundary
            for (int i = 0; i < rows; i++)
                temp[i] = 0;
    
            for (int right = left; right < cols; right++) {
              
                // Update the temporary array with the current
              	// column's values
                for (int row = 0; row < rows; row++) {
                    temp[row] += mat[row][right];
                }
    
                // Find the maximum sum of the subarray for the 
              	// current column boundaries
                int sum = kadane(temp);
    
                // Update the maximum sum found so far
                maxSum = max(maxSum, sum);
            }
        }
    
        return maxSum;
    }

};
