/*
    Author: Melike Vurucu (melikechan)
    Date: 16.02.2024 (DD.MM.YYYY)
    Problem Link: https://cses.fi/problemset/task/1158
    ==================================================
    Time Complexity: O(nx)
    Space Complexity: O(x) (x is the maximum price, n is number of books)
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
    This problem is a knapsack problem, we try to reach the maximal number of pages.

    dp[x] = maximum number of pages with the total price x

    Base case:
    dp[0] = 0
*/
void solve()
{
    int n, x;
    cin >> n >> x;

    vector<ll> price;
    vector<ll> pages;

    for (int i = 0; i < n; i++)
    {
        ll h;
        cin >> h;

        price.push_back(h);
    }

    for (int i = 0; i < n; i++)
    {
        ll s;
        cin >> s;

        pages.push_back(s);
    }

    vector<ll> dp(x + 1, -1);
    dp[0] = 0;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = x; j >= 0; j--)
        {
            if (dp[j] == -1 || j + price[i] > x)
            {
                continue;
            }

            dp[j + price[i]] = max(dp[j + price[i]], dp[j] + pages[i]);
        }
    }

    cout << *max_element(dp.begin(), dp.end());
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
