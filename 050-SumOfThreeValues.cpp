#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int target;
    int currentNumber;
    cin >> n;
    cin >> target;
    vector<pair<int, int>> positionsWithValues;
    
    for (int i = 1; i <= n; ++i) {
        cin >> currentNumber;
        positionsWithValues.push_back({currentNumber, i});
    }
    
    sort(positionsWithValues.begin(), positionsWithValues.end());
    
    int currentTarget;
    int ptr1 = 0;
    int ptr2 = 0;
    
    for (int i = 0; i < n; ++i) {
        currentTarget = target - positionsWithValues[i].first;
        if (currentTarget < 2) {
            break;
        }
        ptr1 = i + 1;
        ptr2 = n - 1;
        while (ptr1 < ptr2) {
            if (positionsWithValues[ptr1].first + positionsWithValues[ptr2].first < currentTarget) {
                ++ptr1;
            } else if (positionsWithValues[ptr1].first + positionsWithValues[ptr2].first > currentTarget) {
                --ptr2;
            } else {
                cout << positionsWithValues[i].second << " " << positionsWithValues[ptr1].second << " " << positionsWithValues[ptr2].second << "\n";
                return 0;
            }
        }
    }
    
    cout << "IMPOSSIBLE";
    
    return 0;
}
