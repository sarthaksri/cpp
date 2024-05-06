#include <iostream>
#include <algorithm>

using namespace std;

struct Job {
    int id;     
    int deadline;   
    int profit; 
};

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n)
{
    sort(arr, arr+n, comparison);

    int result[n];
    bool slot[n];

    for (int i=0; i<n; i++)
        slot[i] = false;

    for (int i=0; i<n; i++)
    {
         for (int j=min(n, arr[i].deadline)-1; j>=0; j--)
         {
             if (slot[j]==false)
             {
                 result[j] = i;  
                 slot[j] = true; 
                 break;
             }
         }
    }

    cout<<"Following is maximum profit sequence of jobs:"<<endl;

    for (int i=0; i<n; i++)
       if (slot[i])
         cout << arr[result[i]].id << " ";
    
}

int main()
{
    Job arr[5];
    cout<<"Enter the job id, deadline and profit for 5 jobs: ";
    for(int i = 0; i < 5; i++)
    {
        cin>>arr[i].id>>arr[i].deadline>>arr[i].profit;
    }

    printJobScheduling(arr, 5);
}