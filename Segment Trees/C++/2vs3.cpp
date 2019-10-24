//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/2-vs-3/

#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define f(i, a, n) for (lli i = a; i < n; i++)
#define fb(i, a, n) for (lli i = n - 1; i >= a; i--)

#define p64 pair<lli, lli>
#define v64 vector<lli>
#define p32 pair<int, int>
#define v32 vector<int>
#define vp64 vector<pair<lli, lli>>
#define vp32 vector<pair<int, int>>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mem(x, y) memset(x, y, sizeof(x))

lli tree[400020];
lli arr[100004];

void build(lli tn, lli st, lli ed)
{
    if (st == ed)
    {
        tree[tn] = arr[st];
        return;
    }

    lli mid = (st + ed) / 2;
    build(tn * 2 + 1, st, mid);
    build(tn * 2 + 2, mid + 1, ed);
    tree[tn] = (tree[tn * 2 + 1] * ((ed - mid) % 2 + 1) + tree[tn * 2 + 2]) % 3;
}

void update(lli tn, lli st, lli ed, lli idx)
{
    if (st == ed)
    {
        if(arr[st]==0)
        arr[st] = 1;
        tree[tn] = arr[st];
        return;
    }
    lli mid = (st + ed) / 2;
    if (idx > mid)
    {
        update(tn * 2 + 2, mid + 1, ed, idx);
    }
    else
    {
        update(tn * 2 + 1, st, mid, idx);
    }
    tree[tn] = (tree[tn * 2 + 1] * ((ed - mid) % 2 + 1) + tree[tn * 2 + 2]) % 3;
}

int query(lli tn, lli st, lli ed, lli lt, lli rt)
{
    if(st > rt or ed < lt)
    {
        return 0;
    }

    if(st>=lt and ed <=rt)
    {
        return (tree[tn]*((rt - ed)%2+1))%3;
    }

    lli mid = (st + ed)/2;
    lli ans1 = query(tn*2+1,st,mid,lt,rt);
    lli ans2 = query(tn*2+2,mid+1,ed,lt ,rt);
    return (ans1 + ans2)%3;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1;
    //cin>>t;
    while (t--)
    {
        lli n;
        cin >> n;
        f(i, 0, n)
        {
            char c;
            cin >> c;
            arr[i] = c - '0';
        }

        build(0, 0, n - 1);

        lli q;
        cin >> q;
        while (q--)
        {
            int m;
            cin >> m;
            if (m == 0)
            {
                lli a, b;
                cin >> a >> b;
                cout << query(0, 0, n - 1, a, b) << endl;
            }
            else
            {
                lli a;
                cin >> a;
                update(0, 0, n - 1, a);
            }
        }
    }
    return 0;
}