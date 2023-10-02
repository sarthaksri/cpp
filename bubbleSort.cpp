#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    int i,j,k;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
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
    bubbleSort(arr, n);
    cout<<"Sorted Array : ";
    for(i=0 ; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}