/*
    Author: Melike Vurucu (melikechan)
    Date: 15.02.2024 (DD.MM.YYYY)
    Problem Link: https://cses.fi/problemset/task/1633
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
    Let's think about the problem as how we can form the number x?

    For example, let's take 3.
    We can form 3 as below:
    - 3

    - 2 + 1
    - 1 + 1 + 1

    - 1 + 2

    1 - 2 - 1
    ------------------
    Also, let's take 4:
    - 4

    - 3 + 1
    - 2 + 1 + 1
    - 1 + 2 + 1
    (we can form 3 as a prefix in 3 ways)

    - 2 + 2
    - 1 + 1 + 1 + 1
    - 1 + 1 + 2
    (we can form 2 as a prefix in 3 ways)

    - 1 + 3

    1 - 3 - 3 - 1
    ------------------

    If you can see the pattern, it is the binomial expansion.
    In binomial expansion, sum of the coefficents is 2^(n-1).

    NOTE: Don't forget that our dices' outcomes are from 1 to 6.
    Therefore, if we want to forget a 7, for example, we MUST need to roll a second dice. (The outcome can be any number from 1-6)
    Another example, if we want to form a 14, this rule also applies. (But we need to roll at least three dices)

    Individually, rolling a standalone number (like 2 itself) has only one way. (Think that we sum up with 0 prefix)
    And forming 0 has only one way: Not throwing a dice.

    So, we can use a bottom-up approach for this problem:
    Base cases:
    - dp[0] = 1
    - dp[1-6] (included) = 2^(n-1)

    Recurrence formula:
    - dp[n] = sum(dp[n - i]) 1 <= i <= 6
    (why sum, because as mentioned above, rolling a standalone number has only one way, **i** symbolizes the number from the dice's income)
*/
void solve()
{
    int n;
    cin >> n;

    vector<ll> dp(n + 1, 0);

    // Base cases
    dp[0] = 1;
    for (ll i = 1; i <= 6; i++)
    {
        dp[i] = (1 << (i - 1));
    }

    // Recurrence
    for (ll i = 7; i <= n; i++)
    {
        for (ll j = 1; j <= 6; j++)
        {
            dp[i] = (dp[i] + dp[i - j]) % mod; // The problem asks the answer in modulo 10^9 + 7
        }
    }

    cout << dp[n];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
