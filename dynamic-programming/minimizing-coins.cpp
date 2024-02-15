/*
    Author: Melike Vurucu (melikechan)
    Date: 15.02.2024 (DD.MM.YYYY)
    Problem Link: https://cses.fi/problemset/task/1634
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
constexpr int intinf = 1e9;

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
    This problem is the classical coin problem.

    It is very common to think a greedy solution: Taking the greatest coin to reaching to the desired sum.
    For example, if the coins are {1, 5, 7} and the desired sum is 11, if we use the greedy approach, the steps will be as follows:
    - 7 (remaining 4)
    - 1 (remaining 3)
    - 1 (remaining 2)
    - 1 (remaining 1)
    - 1 (remaining 0)

    using the greedy approach, we have used 5 coins. But the answer is 3 (5 + 5 + 1). Why?
    Taking the biggest coin is not a feasible way, the desired sum can be formed with smaller coins.

    Let's focus on how can we form the parts of desired sum:
    For example, how many coins do we have to reach to 11?

    Here is minimum number of coins to reach to i (0 <= i <= 11) with given coins:

    | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |
    |---|---|---|---|---|---|---|---|---|---|----|----|
    | 0 | 1 | 2 | 3 | 4 | 1 | 2 | 1 | 2 | 3 |  2 |  3 |
    |---|---|---|---|---|---|---|---|---|---|----|----|

    Therefore, minimum number of coins to reach to the desired sum 11 is 3.
    If we breakdown 11 using available coins:
            11
            ||
            10
          //                               ||  \\
           9                                4   2
       //                          || \\   ||  ||
        8                           4  2    3   1
      //               || \\       || ||   ||  ||
       7                3  1        3  1    2   0
     //        || \\   || ||       || ||   ||
      6         2  0    2  0        2  0    1
  // ||        ||      ||          ||      ||
  5   1         1       1           1       0
//   ||        ||      ||          ||
 4    0         0       0           0
||
 3
||
 2
||
 1
||
 0
-----------------------------------------
     11
     ||
      6
   //   ||
    5    1
// ||   ||
 4  0    0
||
 3
||
 2
||
 1
||
 0
-----------------------------------------
    11
    ||
     4
    ||
     3
    ||
     2
    ||
     1
    ||
     0


    If you have noticed that subtrees are the same for a desired sum x.
    Therefore, we can use the most optimal subtree to reach the desired sum... But, how?
*/
void solve()
{
    int n, x;
    cin >> n >> x;

    /*
        We will use bottom-up approach to find the minimal number of coins to reach desired sum x.

        Our base case will be dp[0] = 0, as we don't need any coin to reach desired sum 0.
        For any desired sum i, and the coin c (c <= i), recurrence relation is:
        dp[i] = min(dp[i], dp[i - c] + 1)

        Initial value of dp array will be INF (a relatively big number)

        If dp[x] = INF, it means we can't reach to the desired sum.
    */

    vector<int> coins;
    for (ll i = 0; i < n; i++)
    {
        int c;
        cin >> c;

        coins.push_back(c);
    }

    vector<int> dp(x + 1, intinf);
    dp[0] = 0;

    for (ll i = 1; i <= x; i++)
    {
        for (int c : coins)
        {
            if (c > i)
            {
                continue;
            }

            dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }

    cout << ((dp[x] == intinf) ? -1 : dp[x]);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
