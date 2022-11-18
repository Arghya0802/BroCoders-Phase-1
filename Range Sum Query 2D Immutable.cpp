// Link: https://leetcode.com/problems/range-sum-query-2d-immutable/description/

class NumMatrix {

private :
int m ;
int n ;
vector<vector<int>> prefixSum ;

public:
    NumMatrix(vector<vector<int>>& mat) 
    {
        // We store the dimmensions in M and N respectively
        int m = mat.size() ;
        int n = mat[0].size() ;
        
        // We resize our prefixSum[][] vector accordingly
        prefixSum.resize(m , vector<int> (n , 0) ) ;

        // First element (0,0) will always be equal to mat[0][0]
        prefixSum[0][0] = mat[0][0] ;

        // We fill the First Row and First Column seperately to avoid Edge Cases

        for(int col = 1 ; col < n ; col++)
        {
            prefixSum[0][col] = prefixSum[0][col - 1] + mat[0][col] ;
        }
        
        for(int row = 1 ; row < m ; row++)
        {
            prefixSum[row][0] = prefixSum[row - 1][0] + mat[row][0] ;
        }

        for(int row = 1 ; row < m ; row++)
        {
            for(int col = 1 ; col < n ; col++)
            {
                // PS[i][j] = mat[i][j] + PS[i - 1][j] + PS[i][j - 1] - PS[i - 1][j - 1]
                prefixSum[row][col] = mat[row][col] + prefixSum[row - 1][col] + prefixSum[row][col - 1] - prefixSum[row - 1][col - 1] ;

            }
        }
    }
 
    int sumRegion(int r1, int c1, int r2, int c2) 
    {
        // To calculate the Sum from (r1 , c1) to (r2 , c2)
        // We store the Entire Sum from (0 , 0) to (r2 , c2) in O(1) Time Complexity
        int totalSum = prefixSum[r2][c2] ;

        // From totalSum, we need to subract (r2 , c1 - 1) , (r1 - 1 , c2) and add (r1 - 1 , c1 - 1) to get our Actual Answer [if they exists]

        int leftColSum = 0  ; // Stores PS[r2][c1 - 1]
        int upperRowSum = 0 ; // Stores PS[r1 - 1][c1]
        int diagonalSum = 0 ; // Stores PS[r1 - 1][c1 - 1]

        // Answer = PS[r2][c2] - PS[r2][c1 - 1] - PS[r1 - 1][c1] + PS[r1 - 1][c1 - 1]
        
        if(c1 - 1 >= 0)
            leftColSum = prefixSum[r2][c1 - 1] ;

        if(r1 - 1 >= 0)
            upperRowSum = prefixSum[r1 - 1][c2] ;

        if(r1 - 1 >= 0 && c1 - 1 >= 0)
            diagonalSum = prefixSum[r1 - 1][c1 - 1] ;

        int ans = totalSum - leftColSum - upperRowSum + diagonalSum ;

        return ans ;
    }
};

// Time Complexity:  O(1) [Average Time Complexity]
// Space Complexity: O(M * N)

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
