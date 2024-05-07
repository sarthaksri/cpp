#include <bits/stdc++.h>
using namespace std;

long getNumberOfWays(long N, vector<long> Coins, vector<long>& selectedCoins)
{
    vector<long> ways(N + 1);
    ways[0] = 1;

    for (int i = 0; i < Coins.size(); i++) {
        for (int j = 0; j < ways.size(); j++) {
            if (Coins[i] <= j) {
                ways[j] += ways[(j - Coins[i])];
                if (ways[j - Coins[i]]) {
                    selectedCoins[j] = Coins[i]; // Record the coin selected at this step
                }
            }
        }
    }

    return ways[N];
}

void printArray(vector<long>& coins)
{
    for (long i : coins)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<long> Coins = {1, 5, 10};
    vector<long> selectedCoins(12, 0); // Initialize selectedCoins vector with size equal to N+1

    cout << "The Coins Array:" << endl;
    printArray(Coins);

    cout << "Solution:" << endl;
    long ways = getNumberOfWays(12, Coins, selectedCoins);
    cout << ways << endl;

    cout << "Coins used: ";
    long remainingAmount = 12;
    while (remainingAmount > 0) {
        cout << selectedCoins[remainingAmount] << " ";
        remainingAmount -= selectedCoins[remainingAmount];
    }
    cout << endl;

    return 0;
}
