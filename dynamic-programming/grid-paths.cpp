/*
    Author: Melike Vurucu (melikechan)
    Date: 16.02.2024 (DD.MM.YYYY)
    Problem Link: https://cses.fi/problemset/task/1638
    ==================================================
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)
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
    Our moves are right or down. Recurrence relation is:
    If cell[i][j] = '*', dp[i][j] = 0
    dp[i][0] = dp[0][i] = 1 (unless '*' is encountered, if '*' is encountered, rest of cells in that row/column are 0)
    dp[i][j] = dp[i-1][j] + dp[i][j-1]
*/
void solve()
{
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n, '.'));
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == '*')
        {
            break;
        }

        dp[i][0] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (grid[0][i] == '*')
        {
            break;
        }

        dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] == '*')
            {
                continue;
            }

            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }

    cout << dp[n - 1][n - 1];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
