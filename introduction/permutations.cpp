/*
    Author: Melike Vurucu (melikechan)
    Date: 05.12.2023 (DD.MM.YYYY)
    Problem Link: https://cses.fi/problemset/task/1070
    ==================================================
    Time Complexity: O(n)
    Space Complexity: O(1)
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
    ll n;
    cin >> n;

    if (n == 1) // There is only one element, thus it doesn't have any adjacent elements.
    {
        cout << 1;
    }
    else if (n < 4) // For cases n = 2 and n = 3, there is no solution.
    {
        /*
            Possible formations for,
            |=======|=======|
            | n = 2 | n = 3 |
            |-------|-------|
            |  1 2  | 1 2 3 |
            |  2 1  | 1 3 2 |
            |=======| 2 1 3 |
                    | 2 3 1 |
                    | 3 1 2 |
                    | 3 2 1 |
                    |=======|

            We can see that there are adjacent elements whose difference is 1.
        */
        cout << "NO SOLUTION";
    }
    else
    {
        /*
            We can divide elements into two halves:
            [1, n/2] and [n/2 + 1, n]
            For even indices, we can choose from the first half.
            For odd indices, we can choose from the second half.
        */
        ll l = n / 2 + 1, r = 1;
        loopi(i, 0, i, n, 1)
        {
            if (!(i & 1))
            {
                cout << l << " ";
                l++;
            }
            else
            {
                cout << r << " ";
                r++;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
