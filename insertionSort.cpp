#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    int i,j,k,key;
    for(i=1; i<n; i++)
    {
       key = arr[i];
       j = i-1;
       while(j>=0 && arr[j] > key)
       {
            arr[j+1] = arr[j];
            j--;
       }
       arr[j+1] = key;
    }
}
int main()
{
    int i,n;
    int arr[] = {10, 60, 40, 90, 70, 50, 30, 80, 20, 100};
    //int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    n = sizeof(arr)/sizeof(int);
    insertionSort(arr, n);
    cout<<"Sorted Array : ";
    for(i=0 ; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}