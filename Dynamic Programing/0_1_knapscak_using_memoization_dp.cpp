#include <bits/stdc++.h>
using namespace std;

// time complexity is n*w

vector<vector<int>> t(5,vector<int> (9,-1));

int KnapSack_recursion(int val[], int wt[], int W, int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (t[n][W] != -1)
        return t[n][W];

    if (wt[n - 1] <= W)
    {
        return t[n][W] = max(val[n - 1] + KnapSack_recursion(val, wt, W - wt[n - 1], n - 1), KnapSack_recursion(val, wt, W, n - 1));
    }

    else if (wt[n - 1] > W)
    {
        return t[n][W] = KnapSack_recursion(val, wt, W, n - 1);
    }
}


int main()
{
   
    int val[] = {10, 40, 50, 70};
    int wt[] = {1, 3, 4, 5};
    int W = 8;
    int n = sizeof(val) / sizeof(val[0]);
    cout << KnapSack_recursion(val, wt, W, n);
    return 0;
}