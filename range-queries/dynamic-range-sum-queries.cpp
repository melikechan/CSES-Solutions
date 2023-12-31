/*
    Author: Melike Vurucu (melikechan)
    Date: 31.12.2023 (DD.MM.YYYY)
    Problem Link: https://cses.fi/problemset/task/1648
    ==================================================
    Time Complexity: O(qlogn)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse4,avx,avx2,bmi,bmi2,popcnt,lzcnt") // default architechture flags, you can use below as fallback
// #pragma GCC target("sse4,bmi,bmi2,popcnt,lzcnt")

// Loops
#define loopi($i, s, es, n, inc) for (ll $i = s; es < n; $i += inc)
#define loopieq($i, s, es, n, inc) for (ll $i = s; es <= n; $i += inc)
#define loopd($i, s, es, n, dec) for (ll $i = s; es > n; $i -= dec)
#define loopdeq($i, s, es, n, dec) for (ll $i = s; es >= n; $i -= dec)

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
/*
    Segment trees are like complete binary trees. Like the array representation of binary trees:
    For index i,
    - 2*i -> left child
    - 2*i + 1 -> right child
*/

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

void update(ll val, int pos, int idx, int tl, int tr)
{
    if (tl == tr)
    {
        segtree[idx] = val;
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            update(val, pos, 2 * idx, tl, tm);
        }
        else
        {
            update(val, pos, 2 * idx + 1, tm + 1, tr);
        }
        segtree[idx] = segtree[2 * idx] + segtree[2 * idx + 1];
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
    return query(2 * idx, l, min(r, tm), tl, tm) + query(2 * idx + 1, max(tm + 1, l), r, tm + 1, tr); // answer of the query is sum of subsegments
}

void solve()
{
    int n, q;
    cin >> n >> q;

    segtree.assign(4 * n, 0);
    vector<ll> arr;
    loopi(i, 0, i, n, 1)
    {
        ll x;
        cin >> x;
        arr.push_back(x);
    }

    build(arr, 1, 0, n - 1);

    loopi(i, 0, i, q, 1)
    {
        int qt;
        cin >> qt;

        if (qt == 1)
        {
            int k;
            ll u;
            cin >> k >> u;
            update(u, k - 1, 1, 0, n - 1);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << query(1, a - 1, b - 1, 0, n - 1) << "\n";
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
