// Link: https://codeforces.com/problemset/problem/1699/B

#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;

    while (t--)
    {
        int m , n ;
        cin >> m >> n ;

        
        vector<vector<int>> ans(m) ; // Instead of declaring the entire (m * n) matrix, we have declared only M rows of the Matrix
        
        for(int i = 0 ; i < m / 2 ; i++) // As we are covering 2 Rows everytime, we run the outer loop m / 2 times
        {
            int c = 0 ;

            if(i % 2 == 1) // As the Pattern gets reversed after every 2 rows, C helps us to decide which pattern to follow
                c = 1 ;

            for(int j = 0 ; j < n / 2 ; j++) // Similarly, we run the inner loop n / 2 times
            {
                if(c == 0) // If C equals 0, we are following Matrix A
                {
                    ans[2 * i].push_back(1) ;
                    ans[2 * i].push_back(0) ;

                    ans[2 * i + 1].push_back(0) ;
                    ans[2 * i + 1].push_back(1) ;

                    c = 1 ; // This helps us to print Matrix B next time
                }

                else // Else we will print Matrix B
                {
                    ans[2 * i].push_back(0) ;
                    ans[2 * i].push_back(1) ;

                    ans[2 * i + 1].push_back(1) ;
                    ans[2 * i + 1].push_back(0) ;

                    c = 0 ;
                }
            }
        }

        for(int i = 0 ; i < m ; i++) // At the end, we print the entire matrix
        {
            for(int j = 0 ; j < n ; j++)
                cout << ans[i][j] << " " ;

            cout << endl ;
        }

    }
    
    return 0 ;
}
