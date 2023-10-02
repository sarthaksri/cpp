#include <iostream>
using namespace std;
void optimizedBubbleSort(int arr[], int n)
{
    int i,j,k,temp;
    bool flag;
    for(i=0; i<n-1; i++)
    {
        flag = true;
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                flag = false;
                swap(arr[j],arr[j+1]);
            }
        }
        if(flag == true)
        break;
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
    optimizedBubbleSort(arr, n);
    cout<<"Sorted Array : ";
    for(i=0 ; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}