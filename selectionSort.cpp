#include <iostream>
using namespace std;
void selectionSort(int arr[], int n)
{
    int i,j,k,c;
    for(i=0; i<n-1; i++)
    {
        c = i;
        for(j=i+1; j<n; j++)
        {
           if(arr[c] > arr[j])
           c = j;
        }
        swap(arr[i], arr[c]);
        for(k=0; k<n; k++)
        {
           cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int i,n;
    int arr[] = {10, 60, 40, 90, 70, 50, 30, 80, 20, 100};
    //int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    n = sizeof(arr)/sizeof(int);
    selectionSort (arr, n);
    cout<<"Sorted Array : ";
    for(i=0 ; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}