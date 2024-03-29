/*
    Author: Melike Vurucu (melikechan)
    Date: 05.12.2023 (DD.MM.YYYY)
    Problem Link: https://cses.fi/problemset/task/1083
    ==================================================
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse4,avx,avx2,bmi,bmi2,popcnt,lzcnt") // default architechture flags, you can use below as fallback
// #pragma GCC target("sse4,bmi,bmi2,popcnt,lzcnt")

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

    // Simply keep a boolean vector that represents if we have encountered this number (0-indexed!)
    vector<bool> v(n);
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v[x - 1] = true;
    }

    // If we didn't encounter number i (0-indexed), return i + 1 (as our answer is 1-indexed)
    for (ll i = 0; i < n; i++)
    {
        if (!v[i])
        {
            cout << i + 1;
            return;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
