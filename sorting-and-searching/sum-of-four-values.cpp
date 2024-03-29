/*
    Author: Melike Vurucu (melikechan)
    Date: 29.12.2023 (DD.MM.YYYY)
    Problem Link: https://cses.fi/problemset/task/1642
    ==================================================
    Time Complexity: O(n^3) (two for loops and one two pointer)
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
    ll n, x;
    cin >> n >> x;

    /*
        We can write x as x = arr[i] + arr[j] + arr[k] + arr[l] for some i, j, k, l.
        If we iterate over i and j values, we can find arr[k] + arr[l] = x - arr[i] - arr[j].
        Therefore, we will find satisfying k and l values for each i and j values.
    */

    // Let's think the values in the array like {value, index} pairs. As the problem wants us to prll the indices, we have to store them.
    vector<pair<ll, ll>> arr;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        arr.push_back({a, i}); // I will store as 0-indexed. (Problem wants the answer as 1-indexed)
    }

    sort(arr.begin(), arr.end());

    /*
        We will select i and j values using a for loop.
        For each i and j values, we will find k and l values using two pointer technique.
    */
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {

            ll a = arr[i].first + arr[j].first;
            ll two_ptr_sum = x - a;

            ll l = j + 1, r = n - 1;

            while (l < r)
            {
                ll b = arr[l].first;
                ll c = arr[r].first;

                if (b + c > two_ptr_sum) // If the sum is bigger than the target, we can decrease the sum by decreasing the right pointer. (going left means decreasing the sum)
                {
                    r--;
                }
                else if (b + c < two_ptr_sum) // If the sum is smaller than the target, we can increase the sum by increasing the left pointer. (going right means increasing the sum)
                {
                    l++;
                }
                else
                {
                    cout << arr[i].second + 1 << " " << arr[j].second + 1 << " " << arr[l].second + 1 << " " << arr[r].second + 1;
                    return;
                }
            }
        }
    }

    cout << "IMPOSSIBLE";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
