/*
    Author: Melike Vurucu (melikechan)
    Date: 29.12.2023 (DD.MM.YYYY)
    Problem Link: https://cses.fi/problemset/task/1640
    ==================================================
    Time Complexity: O(nlogn)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse4,avx,avx2,bmi,bmi2,popcnt,lzcnt") // default architechture flags, you can use below as fallback
// #pragma GCC target("sse4,bmi,bmi2,popcnt,lzcnt")

// Loops
#define loopi($i, s, es, n, inc) for (ll $i = s; es < n; $i += inc)
#define loopieq($i, s, es, n, inc) for (ll $i = s; es <= n; $i += inc)
#define loopd($i, s, es, n, dec) for (ll $i = s; es > n; $i -= dec)
#define loopdeq($i, s, es, n, dec) for (ll $i = s; es >= n; $i -= dec)

using namespace std;

using ll = long long;
using ld = long double;

constexpr ll mod = ll(1e9) + 7;
constexpr ll inf = 2e18;
constexpr int intinf = INT_MAX - 1e3;

inline ll lsb(ll x)
{
    return (x) & (-x);
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto &i : v)
    {
        os << i << " ";
    }
    return os;
}

void solve()
{
    int n, x;
    cin >> n >> x;

    /*
        We can write x as x = arr[i] + arr[j] for some i, j.
        If we iterate over i values, we can find arr[j] = x - arr[i].
        Therefore, it is enough to find one of x - arr[i] values in the array.
    */

    // Let's think the values in the array like {value, index} pairs. As the problem wants us to print the indices, we have to store them.
    vector<pair<int, int>> arr;
    loopi(i, 0, i, n, 1)
    {
        int a;
        cin >> a;
        arr.push_back({a, i}); // I will store as 0-indexed. (Problem wants the answer as 1-indexed)
    }

    // We will use binary search (upper_bound) to find the value.
    // If we go to the previous element of upper_bound, we can find the value.
    sort(arr.begin(), arr.end());

    loopi(i, 0, i, n, 1)
    {
        int a = arr[i].first;
        int b = x - a;

        if (a == b)
        {
            if (i + 1 < n && arr[i + 1].first == a) // If both values are equal, it is enough to check if there is another value with the same value.
            {
                cout << arr[i].second + 1 << " " << arr[i + 1].second + 1;
                return;
            }
        }
        else
        {
            auto it = lower_bound(arr.begin(), arr.end(), pair<int, int>{b, -1}); // The first value is important for us.

            if (it->first == b) // Check if b is in the array.
            {
                cout << arr[i].second + 1 << " " << it->second + 1;
                return;
            }
        }
    }

    cout << "IMPOSSIBLE";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
