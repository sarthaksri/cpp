#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcs(string X, string Y, int m, int n)
{
    int L[m+1][n+1];
    int i,j;
    string res;
    
    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
            L[i][j] = 0;
            
            else if(X[i-1] == Y[j-1])
            L[i][j] = L[i-1][j-1] + 1;
            
            else
            L[i][j] = max(L[i-1][j],L[i][j-1]);
        }
    }
    
    i = m;
    j = n;
    
    while(i > 0 && j > 0)
    {
        if(X[i-1] == Y[j-1])
        {
            res.push_back(X[i-1]);
            i--;
            j--;
        }
            
        
        else if (L[i-1][j] > L[i][j-1])
        i--;
        else
        j--;
    }
    
    reverse(res.begin(), res.end());
    cout<<res;
    
    return L[m][n];
}

int main()
{
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";
    int n1 = S1.size();
    int n2 = S2.size();
    
    cout<<"Length of LCS: "<<lcs(S1,S2,n1,n2);
}