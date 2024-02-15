/*
    Author: Melike Vurucu (melikechan)
    Date: 31.12.2023 (DD.MM.YYYY)
    Problem Link: https://cses.fi/problemset/task/1646
    ==================================================
    Time Complexity: O(qlogn)
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

vector<ll> segtree;
void build(vector<ll> &data, int idx, int tl, int tr)
{
    if (tl == tr)
    {
        segtree[idx] = data[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(data, 2 * idx, tl, tm);                           // build left child
        build(data, 2 * idx + 1, tm + 1, tr);                   // build right child
        segtree[idx] = segtree[2 * idx] + segtree[2 * idx + 1]; // idx contains the sum of left and right subtree (as we have divided into two subsegments)
    }
}

ll query(int idx, int l, int r, int tl, int tr)
{
    if (l > r)
    {
        return 0; // invalid query
    }

    if (l == tl && r == tr)
    {
        return segtree[idx];
    }

    int tm = (tl + tr) / 2;
    return query(2 * idx, l, min(r, tm), tl, tm) + query(2 * idx + 1, max(tm + 1, l), r, tm + 1, tr);
}

// This problem can also be solved with prefix sums, but as I want to get used to segment trees, I have used segment tree.
void solve()
{
    int n, q;
    cin >> n >> q;

    segtree.assign(4 * n, 0);
    vector<ll> arr;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        arr.push_back(x);
    }

    build(arr, 1, 0, n - 1);
    for (ll i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << query(1, l - 1, r - 1, 0, n - 1) << "\n";
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
