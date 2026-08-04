#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int height;
    int width;
    char input;
    int xA = 0;
    int yA = 0;
    int xB = 0;
    int yB = 0;
    cin >> height;
    cin >> width;

    vector<vector<char>> grid(height, vector<char>(width));
    vector<vector<char>> directions(height, vector<char>(width, '-'));

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> input;
            grid[i][j] = input;
            if (grid[i][j] == 'A') {xA = j; yA = i;}
            if (grid[i][j] == 'B') {xB = j; yB = i;}
        }
    }
    
    int directionX[4] = {0, 0, 1, -1};
    int directionY[4] = {1, -1, 0, 0};
    char directionLetters[4] = {'D', 'U', 'R', 'L'};
    int xCopy;
    int yCopy;
    bool BFound = false;
    pair<int, int> currentLocation = {yA, xA};
    queue<pair<int, int>> locations;
    locations.push({yA, xA});

    while (!(locations.empty())) {
        currentLocation = locations.front();
        int y = currentLocation.first;
        int x = currentLocation.second;
        if (x == xB && y == yB) {break;}
        locations.pop();

        for (int i = 0; i < 4; ++i) {
            xCopy = x + directionX[i];
            yCopy = y + directionY[i];
            if (xCopy >= 0 && xCopy < width && yCopy >= 0 && yCopy < height) {
                if (grid[yCopy][xCopy] == '.' || grid[yCopy][xCopy] == 'B') {
                    directions[yCopy][xCopy] = directionLetters[i];
                    if (grid[yCopy][xCopy] == '.') {
                        grid[yCopy][xCopy] = '#';
                    } else {BFound = true;}
                    locations.push({yCopy, xCopy});
                }
            }
        }
    }

    if (!BFound) {cout << "NO"; return 0;}

    int BacktrackX = xB;
    int BacktrackY = yB;
    string output = "";

    while (BacktrackX != xA || BacktrackY != yA) {
        char currentDirection = directions[BacktrackY][BacktrackX];
        int location = find(directionLetters, directionLetters + 4, currentDirection) - directionLetters;
        BacktrackX -= directionX[location];
        BacktrackY -= directionY[location];
        output.push_back(currentDirection);
    }

    reverse(output.begin(), output.end());
    cout << "YES" << "\n";
    cout << output.size() << "\n";
    cout << output << "\n";

    return 0;
}