#include <iostream>
#include <stack>
#include <queue>
using namespace std;
stack <char> s;
queue <char> q;
void input()
{
    q.push('d');
    q.push('a');
    q.push('t');
    q.push('a');
    q.push('b');
    q.push('a');
    q.push('s');
    q.push('e');
}
void function1(char val)
{   
    if(s.empty() || s.top() < val)
    {
        s.push(val);
        return;
    }
    char c = s.top();
    s.pop();
    function1(val);
    if(c != s.top())
    {
        s.push(c);
    }
}
int main()
{
    input();
    while (!q.empty())
    {
        char c = q.front();
        q.pop();
        function1(c);
    }
    stack <char> st = s;
    while (!st.empty()) {
        cout << st.top() <<" ";
        st.pop();
    }
    // queue<char> g = q;
    // while (!g.empty()) {
    //     cout << '\t' << g.front();
    //     g.pop();
    // }
    // cout << '\n';
}
