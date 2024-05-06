#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //assign a vector of vectors of strings with value = [[""]]
        vector<vector<string>> ans(strs.size(),vector<string>(1,""));
        int i,j,x=0,y=0;
        for(i = 0; i < strs.size(); i++)
        {
            for(j = i+1; j < strs.size(); j++)
            {
                if(anagram(strs[i],strs[j]))
                ans[x][y++] = strs[j];
            }
            x = 0;
        }
        return ans;
    }
    bool anagram(string s, string st)
    {
        sort(s.begin(),s.end());
        sort(st.begin(),st.end());
        return s==st;
    }
};

int main()
{
    Solution s;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = s.groupAnagrams(strs);
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}