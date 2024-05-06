#include <iostream>
using namespace std;
void merge(int arr[], int s, int e)
{
    int i,j,k;
    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    k = s;
    for(i = 0; i<len1; i++)
    {
        first[i] = arr[k++];
    }
    k = mid + 1;
    for(i = 0; i<len2; i++)
    {
        second[i] = arr[k++];
    }

    i = 0; j = 0; k = s;
    while(i<len1 && j<len2)
    {
        if(first[i] < second[j])
        arr[k++] = first[i++];
        else
        arr[k++] = second[j++];
    }
    
    while(i < len1)
        arr[k++] = first[i++];

    while(i < len2)
        arr[k++] = first[j++];  

    delete []first;
    delete []second;
}
void mergeSort(int arr[], int s, int e)
{
   if(s>=e)
   return;

   int mid = (s+e)/2;

   mergeSort(arr, s, mid);
   mergeSort(arr, mid+1, e);
   merge(arr, s, e);
}
int main()
{
    int i,n;
    int arr[] = {10, 60, 40, 90, 70, 50, 30, 80, 20, 100};
    //int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    n = sizeof(arr)/sizeof(int);
    mergeSort(arr, 0, n-1);
    cout<<"Sorted Array : ";
    for(i=0 ; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}