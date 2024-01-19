// class Solution {
// public:

//     int n;
//     int t[101][101];
//     int f(vector<vector<int>> &matrix,int row,int col){
//         if(row==n-1){
//             return matrix[row][col];
//         }

//         if(t[row][col]!=-1){
//             return t[row][col];
//         }
//         int sum=matrix[row][col];
//         int mini = INT_MAX;

//         if(row+1<n && col-1>=0)
//         mini= min(mini,sum+f(matrix,row+1,col-1));
//         if(row+1<n)
//         mini= min(mini,sum+f(matrix,row+1,col));
//         if(row+1<n && col+1<n)
//         mini= min(mini,sum+f(matrix,row+1,col+1));

//         return t[row][col] = mini;
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         n=matrix.size();
//         int res=INT_MAX;
//         int row=0;
//         memset(t,-1,sizeof(t));
//         for(int col=0;col<n;col++){
//             res=min(res,f(matrix,row,col));
//         }
//         return res;
//     }
// };


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Number of rows in the matrix
    int m = matrix[0].size(); // Number of columns in the matrix

    // Create a 2D DP (dynamic programming) array to store maximum path sums
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initialize the first row of dp with values from the matrix (base condition)
    for (int j = 0; j < m; j++) {
        dp[0][j] = matrix[0][j];
    }

    // Iterate through the matrix rows starting from the second row
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Calculate the maximum path sum for the current cell considering three possible directions: up, left diagonal, and right diagonal

            // Up direction
            int up = matrix[i][j] + dp[i - 1][j];

            // Left diagonal direction (if it's a valid move)
            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0) {
                leftDiagonal += dp[i - 1][j - 1];
            } else {
                leftDiagonal += 1e9; // A very large negative value to represent an invalid path
            }

            // Right diagonal direction (if it's a valid move)
            int rightDiagonal = matrix[i][j];
            if (j + 1 < m) {
                rightDiagonal += dp[i - 1][j + 1];
            } else {
                rightDiagonal += 1e9; // A very large negative value to represent an invalid path
            }

            // Store the maximum of the three paths in dp
            dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
        }
    }

    // Find the maximum value in the last row of dp, which represents the maximum path sums ending at each cell
    int mini = INT_MAX;
    for (int j = 0; j < m; j++) {
        mini = min(mini, dp[n - 1][j]);
    }

    // The maximum path sum is the maximum value in the last row
    return mini;
    }
};
