#include <iostream>
using namespace std;

struct node 
{
    int item;
    struct node *next;
}*newNode;

struct node *head=NULL,*top;

void push()
{
    int x;
    cout<<"Enter the element to be inserted: ";
    cin>>x;
    newNode = new node;
    newNode->item = x;
    newNode->next = NULL;
    if(head == NULL)
    {
        head = newNode;
        top = newNode;
    }
    else
    {
        top->next = newNode;
        top = newNode;
    }
}
void pop()
{
    struct node *temp;
    temp = head;
    if(head == NULL)
    {
        cout<<"Stack Underflow"<<endl;
        return;
    }
    cout<<"The deleted element is: "<<top->item<<endl;
    while(temp->next != top)
    {
        temp = temp->next;
    }
    top = temp;
    top->next = NULL;
}
void display()
{
    struct node *temp;
    temp = head;
    cout<<"The elements of the stack are: "<<endl;
    while(temp != NULL)
    {
        cout<<temp->item<<endl;
        temp = temp->next;
    }
}

int main()
{
    push();
    display();
    push();
    display();
    push();
    display();
}