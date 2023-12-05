/*
    Author: Melike Vurucu (melikechan)
    Date: 5.12.2023 (DD.MM.YYYY)
    Problem Link: https://cses.fi/problemset/task/1069
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
    string s;
    cin >> s;

    ll ans = 1, cur = 1;
    loopi(i, 1, i, s.size(), 1)
    {
        if (s[i] == s[i - 1])
        {
            cur++;
        }
        else
        {
            ans = max(ans, cur);
            cur = 1;
        }
    }

    cout << max(ans, cur);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
