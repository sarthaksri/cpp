#include <iostream>
#define len 5
using namespace std;

struct Queue 
{
    int arr[len];
    int front, rear;
};

Queue init()
{
    Queue Q;
    Q.front = Q.rear = -1;
    return Q;
}

Queue enqueue(Queue Q, int x)
{
    if(Q.front == (Q.rear+1)%len)
    {
        cout<<"Overflow"<<endl;
    }
    else
    {
        if(Q.front == -1)
        Q.front = 0;
        Q.rear = (Q.rear+1)%len;
        Q.arr[Q.rear] = x;
    }
    return Q;
}

Queue dequeue(Queue Q)
{
    if(Q.front == Q.rear && Q.front == -1)
    {
        cout<<"Underflow"<<endl;
    }
    else
    {
        if(Q.front == Q.rear)
        {
            Q.front = Q.rear = -1;
        }
        else
        Q.front = (Q.front+1)%len;
    }
    return Q;
}

void display(Queue Q)
{
    int i;
    if (Q.rear >= Q.front)
    {
        for (i = Q.front; i <= Q.rear; i++)
            cout<<Q.arr[i]<<" ";
    }
    else
    {
        for (i = Q.front; i < len; i++)
            cout<<Q.arr[i]<<" ";
 
        for (i = 0; i <= Q.rear; i++)
            cout<<Q.arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Queue Q = init();
    Q = enqueue(Q,1);
    Q = enqueue(Q,2);
    Q = enqueue(Q,3);
    Q = enqueue(Q,4);
    Q = enqueue(Q,5);
    Q = enqueue(Q,6);
    Q = dequeue(Q);
    Q = dequeue(Q);
    Q = dequeue(Q);
    Q = dequeue(Q);
    Q = dequeue(Q);
    Q = dequeue(Q);
    display(Q);
}