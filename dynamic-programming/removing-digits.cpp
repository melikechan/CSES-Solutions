/*
    Author: Melike Vurucu (melikechan)
    Date: 16.02.2024 (DD.MM.YYYY)
    Problem Link: https://cses.fi/problemset/task/1637
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

/*
    In this problem, we will use top-down approach.
    Because, we start from a number n and try to reach to 0 by subtracting one of the digits of the number.

    So, we can start by dp[n] = 0, our base case.
    And from n, dp[n - digit] = min(dp[n - digit], dp[n] + 1)

    Because, subtracted digits can be variant (no guarantee that the smallest or the biggest will always give the minimal).
*/
void solve()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, intinf);
    dp[n] = 0;

    string number; // For getting the digits

    for (int i = n; i > 0; i--)
    {
        if (dp[i] == intinf)
        {
            continue;
        }

        number = to_string(i);
        for (char c : number)
        {
            dp[i - (c - '0')] = min(dp[i - (c - '0')], dp[i] + 1);
        }
    }

    cout << dp[0];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
