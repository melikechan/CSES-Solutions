/*
    Author: Melike Vurucu (melikechan)
    Date: 05.12.2023 (DD.MM.YYYY)
    Problem Link: https://cses.fi/problemset/task/1074
    ==================================================
    Time Complexity: O(nlogn)
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
    int n;
    cin >> n;

    vector<ll> sticks;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        sticks.push_back(x);
    }

    sort(sticks.begin(), sticks.end()); // Sort the sticks to find the median in O(1) time.

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans += abs(sticks[i] - sticks[n / 2]);
    }

    cout << ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
