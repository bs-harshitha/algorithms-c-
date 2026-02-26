#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    // dp[i][w] will store the maximum value that can be attained 
    // with weight less than or equal to w using first i items
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; // Base case: no items or no capacity
            } 
            else if (weights[i - 1] <= w) {
                // Max of (including item, excluding item)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], 
                               dp[i - 1][w]);
            } 
            else {
                // Item is too heavy, must exclude
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50;
    int n = values.size();

    cout << "Maximum value in Knapsack: " << knapsack(W, weights, values, n) << endl;

    return 0;
}