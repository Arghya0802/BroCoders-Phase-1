// https://codeforces.com/problemset/problem/1734/C

#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;

    while (t--)
    {
        int n ;
        cin >> n ;

        string s ;
        cin >> s ;

        vector<int> nums(n + 1 , -1) ; // We take a vector of size (N + 1) to keep track of the Elements from 1 to N

        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == '1')
                nums[i + 1] = 1 ; // We follow 1-based Indexing
        }

        long long int ans = 0 ;

        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = i ; j <= n ; j += i) // We start our loop from i and encounter all the multiples of i less than equal to N
            {
                if(nums[j] == 1) // If any of the Multiple is present in Set T, we immediately break out
                    break;
                
                if(nums[j] == -1) // If we haven't encountered the mutliple yet, we increment our ans by 1
                    ans += i ;

                nums[j] = 2 ; // And we mark the Multiple as visited so that we again don't encounter it
            }
        }
      
      cout << ans << endl ; // At the end, we print the MinCost of removing the elements

    }
    

    return 0 ;
}

// Time Complexity:  O(N LogN)
// Space Complexity: O(N)
