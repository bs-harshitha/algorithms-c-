#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int n;
int dist[20][20]; // Distance matrix
int memo[1 << 20][20]; // memo[mask][pos]

int tsp(int mask, int pos) {
    // Base case: all cities visited
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; // Return to starting city
    }

    // Return cached result
    if (memo[mask][pos] != -1) {
        return memo[mask][pos];
    }

    int ans = INF;

    // Try to go to every other city
    for (int city = 0; city < n; city++) {
        // If city is not visited (bit is 0)
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return memo[mask][pos] = ans;
}

int main() {
    n = 4;
    // Example distance matrix (symmetric for simplicity)
    int exampleDist[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dist[i][j] = exampleDist[i][j];

    // Initialize memo table with -1
    for(int i=0; i<(1<<n); i++)
        for(int j=0; j<n; j++)
            memo[i][j] = -1;

    cout << "Minimum distance: " << tsp(1, 0) << endl; // Start at city 0

    return 0;
}