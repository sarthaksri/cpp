#include <iostream>
using namespace std;
int stack[10];
int top = -1;
void push()
{
    if(top == 9)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    int x;
    cout << "Enter the element to be pushed: ";
    cin >> x;
    stack[++top] = x;
}
void pop()
{
    if(top == -1)
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << "The popped element is: " << stack[top--] << endl;
}
void display()
{
    if(top == -1)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "The elements of the stack are: " << endl;
    for(int i = top; i >= 0; i--)
    {
        cout << stack[i] << endl;
    }
}
int main() {
 
    push();
    pop();
    display();
    return 0;
}