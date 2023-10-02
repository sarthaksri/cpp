#include <iostream>
using namespace std;
int partition(int arr[], int s, int e)
{
    int pivotIndex, c=0, i,j, pivot = arr[s];
    for(i=s+1; i<=e; i++)
    {
        if(arr[i] <= pivot)
        c++;
    }
    pivotIndex = s+c;
    swap(arr[s], arr[pivotIndex]);

    i = s; 
    j = e;
    while(i<pivotIndex && j>pivotIndex)
    {
        while(arr[i]<pivot)
        i++;

        while(arr[j]>pivot)
        j--;

        if(i<pivotIndex && j>pivotIndex)
            swap(arr[i++],arr[j--]);
    }

    return pivotIndex;
}
void quickSort(int arr[], int s, int e)
{
    if(s>=e)
        return;
    int p = partition(arr, s, e);  
    quickSort(arr, s, p-1);  
    quickSort(arr, p+1, e);  
}
int main()
{
    int i,n;
    int arr[] = {10, 60, 40, 90, 70, 50, 30, 80, 20, 100};
    //int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    n = sizeof(arr)/sizeof(int);
    quickSort(arr, 0, n-1);
    cout<<"Sorted Array : ";
    for(i=0 ; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}