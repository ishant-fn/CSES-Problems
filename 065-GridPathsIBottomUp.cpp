#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<bool>> grid(n + 2, vector<bool>(n + 2, false));
    vector<vector<int>> paths(n + 2, vector<int>(n + 2, 0));

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

    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= n; ++x) {
            if (grid[y][x]) {
                paths[y][x] = 0;
            } else if (x == 1 && y == 1) {
                paths[y][x] = 1;
            } else {
                paths[y][x] = (paths[y - 1][x] + paths[y][x - 1]) % 1000000007;
            }
        }
    }

    cout << paths[n][n] << "\n";
}