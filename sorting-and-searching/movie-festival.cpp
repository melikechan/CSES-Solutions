/*
    Author: Melike Vurucu (melikechan)
    Date: 05.12.2023 (DD.MM.YYYY)
    Problem Link: https://cses.fi/problemset/task/1629
    ==================================================
    Time Complexity: O(nlogn)
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
    int n;
    cin >> n;

    // 1st solution: Priority queue based
    /*
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (ll i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        pq.push({b, a}); // We will sort by ending times.
    }

    /*
        Why do we choose by the ending time?
        Well, the answer is kind of intuitive: If we want to watch another movie, we have to finish current movie.
        If we choose a movie that has later ending than the others, we will miss the others' starting times.
        But, if we choose a movie that ends as early as possible, we are likely to miss less movies.

        That problem is also called as "The Scheduling Problem".
    */
    /*
    int current_time = 0, ans = 0;

    while (!pq.empty())
    {
        auto [e, s] = pq.top();
        pq.pop();

        if (current_time <= s)
        {
            current_time = e;
            ans++;
        }
    }
    */

    // 2nd solution: Vector + sorting based
    vector<pair<int, int>> movies;
    for (ll i = 0; i < n; i++) // As we only need to iterate through movies, we can just keep a vector and then sort it.
    {
        int a, b;
        cin >> a >> b;
        movies.push_back({b, a});
    }
    sort(movies.begin(), movies.end());

    int current_time = 0, ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (current_time <= movies[i].second)
        {
            current_time = movies[i].first;
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
