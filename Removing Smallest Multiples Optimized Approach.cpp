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
        long long int ans = 0 ;
        
        // In this approach, we don't use an extra array. Instead we use the string given to us
        
        for(int i = 1 ; i <= n ; i++) // As we are following 1-based indexing, we start from i = 1 till i <= N
        {
            int c = 1 ; // C helps us to prepare all the muliples of i

            while (c * i <= n)
            {
                int multiple = c * i ;

                if(s[multiple - 1] == '1') // We check the Multiple is present in T[] or not
                    break ; // If true, we break out

                if(s[multiple - 1] == '0') // If the multiple haven't yet encountered, we increment ans by i
                    ans += i ;

                s[multiple - 1] = '2' ; // We mark it as visited so that we don't count it again

                c++ ; 
            }
            
        }

        cout << ans << endl ;

    }
    

    return 0 ;
}

// Time Complexity:  O(N LogN)
// Space Complexity: O(1)
