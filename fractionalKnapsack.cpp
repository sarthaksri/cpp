#include <bits/stdc++.h>
using namespace std;

struct Item{
    int profit;
    int wt;
};

bool sortProfit(Item &a, Item &b)
{
    float r1 = (a.profit*1.0)/a.wt;
    float r2 = (b.profit*1.0)/b.wt;
    return r1 > r2;
}

int fractionalKnapsack(int w, Item arr[], int n)
{
    int i;
    
    sort(arr, arr+n, sortProfit);
    
    float cost = 0.0;
    
    for(i = 0; i < n; i++)
    {
        if(arr[i].wt <= w)
        {
            cost = cost + arr[i].profit;
            w = w - arr[i].wt;
        }
        else
        {
            cost = cost + (((double)w)/arr[i].wt)*arr[i].profit;
            w = 0;
            break;
        }
    }
    
    return cost;
}

int main()
{
    int W = 50;
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    cout << fractionalKnapsack(W, arr, N);
    return 0;
}