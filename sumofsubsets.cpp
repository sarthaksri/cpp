#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

void sumofsubsets(vector<int> &nums, int target, vector<vector<int>> &result,vector<int> &current, int i)
{
    if(target == 0)
    {
        result.push_back(current);
        return;
    }
    
    if(i >= nums.size() || target < 0)
    return;
    
    //x=0
    sumofsubsets(nums, target, result, current, i+1);
    //x=1
    current[i] = 1;
    sumofsubsets(nums, target - nums[i], result, current, i+1);
    
    //backtrack
    current[i] = 0; 
    
    
}

int main()
{
    vector<int> nums = { 1, 2, 1 };
    int target = 3;
    
    vector<int> current(nums.size(),0);
    vector<vector<int>> result;
    sumofsubsets(nums, target, result, current, 0);
    
    if(result.size() == 0)
    cout<<"No such subset exists";
    
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[j].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
   
}