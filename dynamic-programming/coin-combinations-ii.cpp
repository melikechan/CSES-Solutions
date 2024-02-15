/*
    Author: Melike Vurucu (melikechan)
    Date: 15.02.2024 (DD.MM.YYYY)
    Problem Link: https://cses.fi/problemset/task/1636
    ==================================================
    Time Complexity: O(nx)
    Space Complexity: O(x) (x is the desired sum of money, n is number of coins)
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
    In this problem, we are asked for distinct ways.

    We will use bottom-up approach: (you can take a look at dice-combinations to understand its logic)
    - Our base case will be dp[0] = 1 (there is only one way to reach at 0, without any coin)
    - And, for any desired coin c,
    dp[i] += dp[i - c] | all  c <= i <= x
*/
void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins;
    for (ll i = 0; i < n; i++)
    {
        int c;
        cin >> c;

        coins.push_back(c);
    }

    // Base cases
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int c : coins)
    {
        for (int i = c; i <= x; i++)
        {
            dp[i] = (dp[i] + dp[i - c]) % mod;
        }
    }

    cout << dp[x];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
