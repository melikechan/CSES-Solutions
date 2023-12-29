/*
    Author: Melike Vurucu (melikechan)
    Date: 05.12.2023 (DD.MM.YYYY)
    Problem Link: https://cses.fi/problemset/task/1069
    ==================================================
    Time Complexity: O(|s|) (|s| is the length of the string)
    Space Complexity: O(|s|)
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

    /*
        Store two variables:
        ans -> to store the maximal answer so far
        cur -> to store current state (how many consequent same letters)
    */
    ll ans = 1, cur = 1;

    loopi(i, 1, i, s.size(), 1)
    {
        if (s[i] == s[i - 1]) // If current letter is same with the previous, increase current state by one.
        {
            cur++;
        }
        else // Take the maximal and reset current state.
        {
            ans = max(ans, cur);
            cur = 1;
        }
    }

    cout << max(ans, cur); // Our answer is the maximum one.
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
