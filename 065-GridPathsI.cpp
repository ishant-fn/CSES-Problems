#include <bits/stdc++.h>
using namespace std;

long long FindPaths(vector<vector<bool>> &grid, int x, int y, int n, vector<vector<int>> &paths) {
    long long totalPaths = 0;
    if (paths[y][x] != -1) {
        return paths[y][x];
    }
    if (x == n && y == n && !grid[y][x]) {
        paths[y][x] = 1;
        return 1;
    }
    if (grid[y][x]) {
        paths[y][x] = 0;
        return 0;
    }
    totalPaths = (totalPaths + FindPaths(grid, x + 1, y, n, paths)) % 1000000007;
    totalPaths = (totalPaths + FindPaths(grid, x, y + 1, n, paths)) % 1000000007;
    paths[y][x] = totalPaths;
    return totalPaths;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<bool>> grid(n + 2, vector<bool>(n + 2, false));
    vector<vector<int>> paths(n + 2, vector<int>(n + 2, -1));

    string row;

    for (int i = 0; i < n; i++) {
        cin >> row;
        for (int j = 0; j < n; j++) {
            if (row[j] == '*') {
                grid[i + 1][j + 1] = true;
            }
        }
    }

    for (int i = 0; i < n + 2; i++) {
        grid[0][i] = true;
        grid[n + 1][i] = true;
        grid[i][0] = true;
        grid[i][n + 1] = true;
    }

    FindPaths(grid, 1, 1, n, paths);

    cout << paths[1][1] << "\n";
}