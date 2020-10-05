//The link for the question is https://cses.fi/problemset/task/1624/

#include <bits/stdc++.h>
#include <cstring>
#include <limits>
using namespace std;
#define ll long long int
#define lli long long int
#define fw(i, s, e) for (ll i = s; i < e; ++i)
#define fe(i, s, e) for (ll i = s; i <= e; ++i)
#define fb(i, e, s) for (ll i = e; i >= s; --i)
#define L(T)  \
    ll T;     \
    cin >> T; \
    while (T--)
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define mem(a, i) memset(a, i, sizeof(a))
#define ld long double
#define endl "\n"
#define in(P) \
    ll P;     \
    cin >> P;
 
char arr[8][8];
ll d1[14];
ll d2[14];
ll col[16];
int ways;
// bool check(int n)
// {
//     if (n >= 0)
//         return 0;
// }
 
void search(ll row)
{
    if (row == 8)
    {
        ways++;
        return;
    }
    for (ll c = 0; c < 8; c++)
    {
        if (col[c] || d1[row + c] || d2[row - c + 7] || arr[row][c])
        {
            continue;
        }
        col[c] = d1[row + c] = d2[row - c + 7] = 1;
        search(row + 1);
        col[c] = d1[row + c] = d2[row - c + 7] = 0;
    }
}
 
int main()
{
    FASTIO
    // L(T)
    {
        mem(col, 0);
        mem(d1, 0);
        mem(d2, 0);
 
        fw(i, 0, 8)
        {
            char x[17];
            cin >> x;
            fw(j, 0, 8)
            {
                if (x[j] == '*')
                {
                    arr[i][j] = 1;
                }
            }
        }
        search(0);
        cout << ways << endl;
    }
    return 0;
}
