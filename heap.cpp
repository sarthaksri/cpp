#include <iostream>
using namespace std;

class heap
{
    public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1)
        {
            int parent = index/2;
            if(arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                parent = index;
            }
            else
            {
                return;
            }
        }
    }

    void deleteFromHeap()
    {
        if(size == 0)
        {
            cout<<"Nothing to delete"<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i;
        while(i<size)
        {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[leftIndex]>arr[i])
            {
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[rightIndex] > arr[i])
            {
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for(int i=1; i<=size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

void heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[left] > arr[largest])
    largest = left;
    if(right <= n && arr[right] > arr[largest])
    largest = right;

    if(largest != i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    heap h;
    int i;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print(); 
    h.deleteFromHeap();
    h.print();
    int arr[6] = {-1,50,55,53,52,54};
    int n = 5;
    for(i = n/2; i>0; i--)
    {
        heapify(arr, n, i);
    }
    cout<<"Heapified: \n";
    for(i = 1; i<=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}