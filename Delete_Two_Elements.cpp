#include <bits/stdc++.h>
using namespace std;

long long int Delete_Elements(vector<int> &nums, int n)
{
    double sum = 0;

    for (int arr : nums)
        sum += arr;

    double  mean = sum / n;

    // If target is not an Integer, we directly return 0
    double target = 2 * mean ;

    if(floor(target) != ceil(target))
        return 0 ;

    long long int k = target ;

    map<long long int, int> map;
    long long int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int arr = nums[i];

        int key = k - arr;

        if (map.find(key) != map.end())
            ans += map[key];

        map[arr] += 1;
    }

    return ans ;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> nums(n);

        for (int i = 0; i < n; i++)
            cin >> nums[i];

        // double sum = 0.0 ;

        long long int ans = Delete_Elements(nums, n);

        cout << ans << endl;
    }

    return 0;
}