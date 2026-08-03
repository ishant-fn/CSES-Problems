#include <bits/stdc++.h>
using namespace std;

int MapOutRoom(vector<vector<char>> &grid, int y, int x) {
    if (y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size()) {
        return 0;
    } else if (grid[y][x] == '#') {
        return 0;
    } else {
        grid[y][x] = '#';
        MapOutRoom(grid, y, x - 1);
        MapOutRoom(grid, y, x + 1);
        MapOutRoom(grid, y - 1, x);
        MapOutRoom(grid, y + 1, x);
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int height;
    int width;
    int rooms = 0;
    cin >> height;
    cin >> width;

    vector<vector<char>> grid(height, vector<char>(width));

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            char input;
            cin >> input;
            grid[i][j] = input;
        }
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (grid[y][x] == '.') {
                rooms++;
                MapOutRoom(grid, y, x);
            }
        }
    }

    cout << rooms << "\n";
    return 0;
}