// LeetCode: https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
// GFG: https://practice.geeksforgeeks.org/problems/sub-array-sum-divisible-by-k2617/1

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        // In this question, we will keep track of all the prefixSum % k , and whenever we encounter any prefixSum % k again, we increment ans by it's count
      
        int n = nums.size() ;

        // Prefix-Sum will help us keep track of the count of subarrays whose sum is divisible by K
        int prefixSum = 0 ;

        // Map will help us keep track of all the prefixSum % k subarrays
        unordered_map<int , int> map ;
        int ans = 0 ;

        map[0] = 1 ; // To handle an edge case, where (prefixSum % k == 0) happens at the very last index
        
        for(int i = 0 ; i < n ; i++)
        {
            prefixSum += nums[i] ;

            // As we are dealing with -ve numbers, we have to use properties of MOD to generate the correct key else we will get wrong ans
            int key = ( (prefixSum % k) + k ) % k ;
            
            // If the key is already present, we will increment ans by map[key]
            if(map.find(key) != map.end() )
                ans += map[key] ;
            
            // We increment the count by key by 1 and store it inside the map
            map[key] += 1 ;
        }

        return ans ;

    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
