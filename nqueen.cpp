#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
    int i,j;
    
    //same column
    for(i = 0; i < n; i++)
    {
        if(board[i][col] == 1)
        return false;
    }
    
    //upper left diagonal
    for(i = row, j = col; i>=0 && j>=0; i--,j--)
    {
        if(board[i][j] == 1)
        return false;
    }
    
    //upper right diagonal
    for(i = row, j = col; i>=0 && j<n; i--,j++)
    {
        if(board[i][j] == 1)
        return false;
    }
    
    return true;
    
}

bool solveNqueen(vector<vector<int>> &board, int row, int n)
{
    if(row == n)
    return true;
    
    int j;
    
    for(j = 0; j < n; j++)
    {
        if(isSafe(board, row, j, n))
        {
            board[row][j] = 1;
            
            //recursion
            if(solveNqueen(board, row+1, n))
            return true;
            
            //backtrack
            board[row][j] = 0;
        }
    }
    
    return false;
}

void displaySolution(vector<vector<int>> &board, int n)
{
    int i,j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

void solveNqueen(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    if(solveNqueen(board, 0, n))
    {
        cout<<"Solution:"<<endl;
        displaySolution(board, n);
    }
    else
    cout<<"Solution not found";
    
}

int main()
{
    int n;
    cout<<"Enter the value of N for n-queens: ";
    cin>>n;
    solveNqueen(n);
}