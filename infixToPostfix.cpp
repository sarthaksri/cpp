#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;
int operatorPrecedence(char c){
    switch (c)
    {
    case '+': 
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;  
    case '^':
        return 3;
        break;      
    default:
        break;
    }
}
int main()
{
    stack<char> s;
    char *postfix;
    char infix[100];
    cout<<"Enter the infix expression: ";
    cin.getline(infix,100);
    cout<<infix;
}