#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
    return a.second < b.second;
}

int jobSchedule(vector<pair<int,int>>& a) {
    sort(a.begin(), a.end(), cmp);
    int c = 1; 
    int i = 0;
	
    for (int j = 1; j < a.size(); j++) {
        if (a[j].first >= a[i].second) {
			c++;
            i = j;
		}
    }
    return c;
}

int main() 
{
    vector<pair<int,int>> arr = { { 800, 1000 }, { 800, 900 }, { 900, 1000 }, { 850, 950 }};
    int c = jobSchedule(arr);
    cout << "Minimum number of taxis required based on given schedule: " << c;
    return 0;
}
