#include <bits/stdc++.h>
using namespace std;

bool grid[9][9] = {false};
int directions[48];

int paths (int currentStep, int x, int y) {
    if (grid[y][x]) {
        return 0;
    }
    if (x == 1 && y == 7) {
        if (currentStep == 48) {
            return 1;
        } else {
            return 0;
        }
    }
    if (currentStep == 48) {
        return 0;
    }

    if (grid[y - 1][x] && grid[y + 1][x] && !grid[y][x - 1] && !grid[y][x + 1]) return 0;
    if (grid[y][x - 1] && grid[y][x + 1] && !grid[y - 1][x] && !grid[y + 1][x]) return 0;

    grid[y][x] = true;
    int direction = directions[currentStep];
    int totalPaths = 0;

    if (direction == 0) {
        totalPaths += paths(currentStep + 1, x, y - 1);
    } else if (direction == 1) {
        totalPaths += paths(currentStep + 1, x, y + 1);
    } else if (direction == 2) {
        totalPaths += paths(currentStep + 1, x - 1, y);
    } else if (direction == 3) {
        totalPaths += paths(currentStep + 1, x + 1, y);
    } else if (direction == 4) {
        totalPaths += paths(currentStep + 1, x, y - 1);
        totalPaths += paths(currentStep + 1, x, y + 1);
        totalPaths += paths(currentStep + 1, x - 1, y);
        totalPaths += paths(currentStep + 1, x + 1, y);
    }
    grid[y][x] = false;
    return totalPaths;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; i++) {
        grid[0][i] = true;
        grid[8][i] = true;
        grid[i][0] = true;
        grid[i][8] = true;
    }

    int x = 1;
    int y = 1;
    string input;
    cin >> input;

    for (int i = 0; i < 48; i++) {
        char currentChar = input[i];
        if (currentChar == 'U') {
            directions[i] = 0;
        } else if (currentChar == 'D') {
            directions[i] = 1;
        } else if (currentChar == 'L') {
            directions[i] = 2;
        } else if (currentChar == 'R') {
            directions[i] = 3;
        } else if (currentChar == '?') {
            directions[i] = 4;
        }
    }

    cout << paths(0, x, y) << "\n";
}