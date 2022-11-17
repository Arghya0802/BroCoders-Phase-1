// Link: https://leetcode.com/problems/product-of-array-except-self/description/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
      
        int n = nums.size() ;
        
        vector<int> ans(n , 1) ;
    
        int product = 1 ;

        // Calculate Product of Array except Number from the left and store it in the array

        for(int i = 0 ; i < n ; i++)
        {
            ans[i] = product ;

            product *= nums[i] ;
        }

        // As the Product of Array from the Left excluding i-th Index is already stored,
        // Now we need to calculate the Product of Array except i-th Index from right
        // We multiply the values and store the result in ans[i]
    
        product = nums[n - 1] ;
    
        for(int i = n - 2 ; i >= 0 ; i--)
        {
            ans[i] *= product ;

            product *= nums[i] ;
        }

        return ans ;
}
};

// Time Complexity:  O(N)
// Space Complexity: O(1) [If we dont include the ans[] array into our Space Complexity]
