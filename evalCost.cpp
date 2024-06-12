#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCost(vector<int>p, int n, int k)
{
    if(n == 0)
    return 0;

    sort(p.begin(), p.end());
    int i = 0, cost = 0, j;

    while(k <= p.size()) 
    {
        cost = cost + p[i];
        i++;
        for(j = 1; j <= k; j++)
        p.pop_back();
    }
    return cost;
    
}

int maxCost(vector<int>p, int n, int k)
{
    if(n == 0)
    return 0;

    sort(p.begin(), p.end(), greater<int>());
    int i = 0, cost = 0, j;

    while(k <= p.size())
    {
        cost = cost + p[i];
        i++;
        for(j = 1; j <= k; j++)
        p.pop_back();
    }
    return cost;
}

int main()
{
    vector<int> price = {3, 2, 1, 4};
    int n = price.size();
    int k = 2;
    cout<<"Minimum Cost: "<<minCost(price,n,k)<<endl;
    cout<<"Maximum Cost: "<<maxCost(price,n,k)<<endl;
}