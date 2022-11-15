// https://codeforces.com/problemset/problem/1739/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> d(n);

        for (int i = 0; i < n; i++)
            cin >> d[i];

        vector<int> ans(n); // Declaring our ans[] array

        ans[0] = d[0]; // First element of both ans[] and d[] are same
        int prev = d[0]; // Prev Element is also initlaised with d[0]

        bool isPossible = true; // Helps us to decide whether to print -1 or ans[] vector

        for (int i = 1; i < n; i++)
        {
            // Using properites of MOD, we calculate x1 and x2
            int x1 = prev + d[i]; 
            int x2 = prev - d[i];

            if(x1 >= 0 && x2 < 0) // Either x1 is positive and x2 is negative
            {
                ans[i] = x1 ;
                prev = x1 ;
            }

            else if(x1 < 0 && x2 >= 0) // Or x2 is positive and x1 is negative
            {
                ans[i] = x2 ;
                prev = x2 ;
            }

            else if(x1 == x2) // Or x1 is equal to x2
            {
                ans[i] = x1 ;
                prev = x2 ;
            }

            else // Otherwise both are positives which is not possible, so we break out of the loop
            {
                isPossible = false ;
                break;
            }
        }

        if (isPossible == false) // If isPossible is false, we print -1
        {
            cout << -1 << endl;
        }

        else // Otherwise we print ans[]
        {
            for (int i = 0; i < n; i++)
                cout << ans[i] << " ";

            cout << endl;
        }
    }

    return 0;
}

// Time Complexity:  O(N)
// Space Complexity: O(N) or O(1) depends on whether we consider ans[] vector as space used by us or not
