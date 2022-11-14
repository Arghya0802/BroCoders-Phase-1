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

        if(n % 2 == 1)
        {
            cout << -1 << endl ;
            continue;
        }

        int a = 1 ;
        int b = a ;

        int c = (n / 2) ^ a ;

        cout << a << " " << b << " " << c << endl ;

    }
    
    return 0 ;
}