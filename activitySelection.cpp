
#include <bits/stdc++.h> 
#include <vector>

#include <algorithm>
using namespace std; 

void printMaxActivities(int s[], int f[], int n) 
{ 
	int i,j;
	cout<<"Following activities will be selected: ";
	
	i = 0;
	cout<<i<<" ";
	
	for(j = 1; j < n;  j++)
	{
	    if(s[j] >= f[i])
	    {
	        cout<<j<<" ";
	        i = j;
	    }
	    
	}
} 

bool activityCompare(const pair<int,int>&p1, const pair<int,int>&p2)
{
    return p1.second < p2.second;
}

void printMaxActivities2(vector<pair<int,int>> activity) 
{ 
	sort(activity.begin(), activity.end(), activityCompare);
	
	cout<<"Following activities will be selected: ";
	int i = 0;
	cout<<"("<<activity[i].first<<","<<activity[i].second<<")";
	
	for(int j = 1; j < activity.size(); j++)
	{
	    if(activity[j].first >= activity[i].second)
	    {
	        cout<<", ("<<activity[j].first<<","<<activity[j].second<<")";
	        i = j;
	    }
	}
} 

int main() 
{ 
// 	int s[] = { 1, 3, 0, 5, 8, 5 }; 
// 	int f[] = { 2, 4, 6, 7, 9, 9 }; 
	vector<pair<int,int>> activity = { { 5, 9 }, { 1, 2 }, { 3, 4 },
                                       { 0, 6 }, { 5, 7 }, { 8, 9 } };
// 	int n = sizeof(s) / sizeof(s[0]); 

// 	printMaxActivities(s, f, n); 

    printMaxActivities2(activity); 
	return 0; 
} 
