#include <bits/stdc++.h>
using namespace std;


struct Item {
    int p; // marks
    int wt; // duration
};


int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, Item items[], int n, vector<vector<int>> &dp)
{
    int i, w;
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (items[i - 1].wt <= w)
                dp[i][w] = max(items[i - 1].p + dp[i - 1][w - items[i - 1].wt], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[i-1][W];
}


int main()
{
    Item items[] = { {8, 1}, {12, 2}, {10, 4}, {15, 5} };
    int W = 5;
    int n = sizeof(items) / sizeof(items[0]);
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    cout << knapSack(W, items, n, dp);

    return 0;
}
