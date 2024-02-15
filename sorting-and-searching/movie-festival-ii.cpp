/*
    Author: Melike Vurucu (melikechan)
    Date: 05.12.2023 (DD.MM.YYYY)
    Problem Link: https://cses.fi/problemset/task/1632
    ==================================================
    Time Complexity: O(nlogk) (n is number of films, k is number of persons)
    Space Complexity: O(n + k)
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
    int n, k;
    cin >> n >> k;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> films;
    multiset<int> persons;

    for (ll i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        films.push({b, a}); // We will sort by ending times.
    }

    /*
        We will keep person's ending time in multiset.

        Why multiset?
        - Multiple persons can have same finishing time.
        - We can use binary search to check if we can start to the film.
          By taking upper bound of starting time and going to the previous one. (If we go to one step back, we can find the earliest starting time.)
    */
    for (ll i = 0; i < k; i++)
    {
        persons.insert(0);
    }

    int current_time = 0, ans = 0;
    while (!films.empty())
    {
        auto [e, s] = films.top();
        films.pop();

        auto it = persons.upper_bound(s);
        if (it != persons.begin())
        {
            persons.erase(--it); // Assign person at (it - 1) to the incoming film
            persons.insert(e);
            ans++;
        }
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
