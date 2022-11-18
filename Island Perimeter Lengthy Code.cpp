// Link: https://leetcode.com/problems/island-perimeter/description/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        // The sides of Land surrounded by water will contribute to our Perimeter
        int m = grid.size() ;
        int n = grid[0].size() ;

        int ans = 0 ;

        for(int row = 0 ; row < m ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                // If we are having water, we should move on
                if(grid[row][col] == 0)
                    continue ; 

                // If we are in the First row, Upward side will always be facing water
                if(row == 0)
                    ans += 1 ; 

                // If we are in the Last row, Downward side will always be facing water
                if(row == m - 1)
                    ans += 1 ; 

                // If we are in the First Column, Leftward side will always be facing water
                if(col == 0) 
                    ans += 1 ;
                
                // If we are in the Last Column, Rightward side will always be facing water
                if(col == n - 1)
                    ans += 1 ;

                // Now, we check on the four sides of the land

                // Upwards direction check 
                if(row - 1 >= 0)
                {
                    int up = grid[row - 1][col] ;

                    if(up == 0)
                        ans += 1 ;
                }

                // Downwards direction check
                if(row + 1 < m)
                {
                    int down = grid[row + 1][col] ;

                    if(down == 0)
                        ans += 1 ;
                }

                // Leftward direction check
                if(col - 1 >= 0)
                {
                    int left = grid[row][col - 1] ;

                    if(left == 0)
                        ans += 1 ;
                }

                // Rightward direction check
                if(col + 1 < n)
                {
                    int right = grid[row][col + 1] ;

                    if(right == 0)
                        ans += 1 ;
                }
            }
        }

        return ans ; // At the end, we return our ans containing the count of sides of land surrounded by water
        
    }
};
