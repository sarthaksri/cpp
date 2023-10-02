#include<iostream>
using namespace std;
int queue[10];
int front = -1;
int rear = -1;
void enqueue()
{
    if(rear == 9)
    {
        cout << "Queue Overflow" << endl;
        return;
    }
    int x;
    cout << "Enter the element to be inserted: ";
    cin >> x;
    queue[++rear] = x;
    if(front == -1)
    {
        front = 0;
    }
}
void dequeue()
{
    if(front == -1)
    {
        cout << "Queue Underflow" << endl;
        return;
    }
    cout << "The deleted element is: " << queue[front++] << endl;
    if(front > rear)
    {
        front = rear = -1;
    }
}
void display()
{
    if(front == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "The elements of the queue are: " << endl;
    for(int i = front; i <= rear; i++)
    {
        cout << queue[i] << endl;
    }
}
int main() {
    int choice;
    do
    {
        cout << "Enter 1 to insert an element" << endl;
        cout << "Enter 2 to delete an element" << endl;
        cout << "Enter 3 to display the elements" << endl;
        cout << "Enter 4 to exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: cout << "Exit" << endl;
                    break;
            default: cout << "Invalid choice" << endl;
        }
    }while(choice != 4);
    return 0;
}