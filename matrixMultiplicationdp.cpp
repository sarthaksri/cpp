#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int matrixChainMemoised(int arr[], int i, int j, vector<vector<int>> &dp, vector<vector<pair<int,int>>> &split)
{
    if(i == j)
    return 0;
    
    if(dp[i][j] != -1)
    return dp[i][j];
    
    dp[i][j] = INT_MAX;
    for(int k = i; k < j; k++)
    {
        int cost = matrixChainMemoised(arr, i, k, dp, split) + matrixChainMemoised(arr, k+1, j, dp, split) + arr[i-1]*arr[k]*arr[j];
        if(cost < dp[i][j])
        {
            dp[i][j] = cost;
            split[i][j] = {k,k+1};
        }
    }
    return dp[i][j];
}

void printBrackets(int i, int j, vector<vector<pair<int,int>>> &split)
{
    if(i == j)
    {
        cout<<"A"<<i;
        return;
    }
    cout<<"(";
    printBrackets(i, split[i][j].first, split);
    cout<<"*";
    printBrackets(split[i][j].second, j, split);
    cout<<")";
}

void MatrixChainOrder(int arr[], int n)
{
    vector<vector<int>>dp(n, vector<int>(n,-1));
    vector<vector<pair<int, int>>> split(n, vector<pair<int, int>>(n)); 
    
    int result = matrixChainMemoised(arr, 1, n-1, dp, split);
    cout << "Minimum number of multiplications is " << result << endl;
    cout << "Optimal Parenthesization: ";
    printBrackets(1, n - 1, split);
    cout << endl;
    
}

int main()
{
    int arr[] = { 1, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    MatrixChainOrder(arr, n);
}