// Link: https://leetcode.com/problems/island-perimeter/description/

class Solution {
private :

// Boundary_Water_Bodies() function helps us to keep track of the Water Bodies present at the Boundaries

int boundary_Water_Bodies(int row , int col , int m , int n)
{
    int count = 0 ;

    if(row == 0)
        count += 1 ;

    if(row == m - 1)
        count += 1 ;

    if(col == 0)
        count += 1 ;

    if(col == n - 1)
        count += 1 ;

    return count ;
}

bool isValid(int row , int col , int m , int n , vector<vector<int>> &grid)
{
    if(row < 0 || row >= m || col < 0 || col >= n) // Checking if cooridnates are valid or not
        return false ;

    else if(grid[row][col] == 1) // If Valid, they should be surrounded by an water body
        return false ;

    return true ;
}

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
                
                // To shorten the code, we can declare a couple of funcions to help us improve our code readibility

                // If our land is present at either of the boundaries, then it has to be surrounded by atleat one water body
                ans += boundary_Water_Bodies(row , col , m , n) ;
                
                // Instead of manually checking in all 4 directions, we can use vectors to ease our job
                vector<int> dirX = {-1 , 1 , 0 , 0} ;
                vector<int> dirY = {0 , 0 , -1 , 1} ;

                for(int index = 0 ; index < 4 ; index++)
                {
                    int newX = row + dirX[index] ;
                    int newY = col + dirY[index] ;

                    // IsValid() function checks if the New-X coordinate and New-Y coordinate are valid or not and also if an Water Body is present at grid[newX][newY] or not

                    if(isValid(newX , newY , m , n , grid) == true)
                        ans += 1 ;
                }
            }
        }

        return ans ; // At the end, we return our ans containing the count of sides of land surrounded by water
        
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
