#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*head;

void pushEnd(int x)
{
    struct node *temp = new node;
    temp->data = x;
    temp->next = nullptr;
    if(head == nullptr)
    {
        head = temp;
    }
    else
    {
        struct node *ptr = head;
        while(ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void pushBeg(int x)
{
    struct node *temp = new node;
    temp->data = x;
    temp->next = head;
    head = temp;
    
}

void display()
{
    struct node *temp;
    temp = head;
    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    head = nullptr;
    pushBeg(9);
    display();
    pushBeg(10);
    display();
    pushEnd(15);
    display();
    pushBeg(16);
    display();
}
