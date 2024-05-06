#include <bits/stdc++.h> 
#include <iostream>
#include <algorithm>
using namespace std;

int max(int a, int b) { 
    return (a > b) ? a : b; 
} 
  

int max(int a, int b, int c) { 
    return max(max(a, b), c); 
}

int crossSum(int *arr, int m, int s, int e)
{
    int i,j;
    int maxL = arr[m], maxR = arr[m + 1], sum = 0;
    
    for(i = m; i >= s; i--)
    {
        sum = sum + arr[i];
        if(maxL < sum)
        maxL = sum;
    }
    
    sum = 0;
    
    for(i = m+1 ; i <= e; i++)
    {
        sum = sum + arr[i];
        if(maxR < sum)
        maxR = sum;
    }
    
    return max(maxR+maxL, maxL, maxR);
}

int maxSubarraySum(int *arr, int s, int e)
{
    if(s == e)
    return arr[s];
    
    if(s > e)
    return INT_MIN;
    
    int mid = s + (e - s)/2;
    
    return max(maxSubarraySum(arr, s, mid), maxSubarraySum(arr, mid+1, e), crossSum(arr, mid, s, e));
}


int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr)/sizeof(int);
    int s = maxSubarraySum(arr, 0, n-1);
    cout<<"Max sum: "<<s;
}